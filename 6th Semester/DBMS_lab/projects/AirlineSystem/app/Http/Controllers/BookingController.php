<?php

namespace App\Http\Controllers;

use App\Models\Booking;
use App\Models\Flight;
use App\Models\Passenger;
use Illuminate\Http\Request;
use App\Mail\BookingConfirmationMail;
use Illuminate\Support\Facades\Mail;

class BookingController extends Controller
{
    public function index()
    {
        $bookings = Booking::with(['passenger', 'flight'])->get();
        return view('bookings.index', compact('bookings'));
    }

    public function create(Request $request)
    {
        $flight = null;
        $passenger = null;
        
        // If flight_id is provided, get the flight details
        if ($request->has('flight_id')) {
            $flight = Flight::with(['departureAirport', 'arrivalAirport'])->findOrFail($request->flight_id);
        }
        
        // If user is authenticated, get their passenger record or create one
        if (auth()->check()) {
            $passenger = Passenger::where('user_id', auth()->id())->first();
            
            // If no passenger record exists, create one
            if (!$passenger) {
                $user = auth()->user();
                $passenger = Passenger::create([
                    'Name' => $user->name,
                    'Email' => $user->email,
                    'Phone' => '',
                    'Passport_No' => '',
                    'user_id' => $user->id,
                ]);
            }
        }
        
        // Get all flights for dropdown (if no specific flight selected)
        $flights = Flight::with(['departureAirport', 'arrivalAirport'])
            ->where('Departure_Time', '>', now())
            ->orderBy('Departure_Time')
            ->get();
            
        // Get all passengers for admin use
        $passengers = Passenger::all();
        
        return view('bookings.create', compact('flight', 'passenger', 'flights', 'passengers'));
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'passenger_id' => 'required|integer|exists:passengers,Passenger_ID',
            'flight_id' => 'required|integer|exists:flights,Flight_ID',
            'booking_date' => 'required|date',
            'passenger_count' => 'required|integer|min:1|max:9',
            'seat_class' => 'required|string|in:economy,premium,business',
        ]);
        
        // Get flight details for pricing
        $flight = Flight::findOrFail($validated['flight_id']);
        
        // Calculate dynamic pricing
        $basePrice = $flight->price ?? 299;
        $taxes = 25;
        $classMultipliers = [
            'economy' => 1.0,
            'premium' => 1.5,
            'business' => 2.5
        ];
        
        $multiplier = $classMultipliers[$validated['seat_class']];
        $pricePerPassenger = ($basePrice * $multiplier) + $taxes;
        $totalAmount = $pricePerPassenger * $validated['passenger_count'];
        
        // Set default values
        $validated['booking_date'] = $validated['booking_date'] ?? now()->toDateString();
        $validated['status'] = 'pending'; // Always start as pending
        
        Booking::create([
            'Passenger_ID' => $validated['passenger_id'],
            'Flight_ID' => $validated['flight_id'],
            'Booking_Date' => $validated['booking_date'],
            'Status' => $validated['status'],
            'passenger_count' => $validated['passenger_count'],
            'seat_class' => $validated['seat_class'],
        ]);
        
        return redirect()->route('user.bookings.index')->with('success', 'Booking created successfully and is pending admin approval.');
    }

    public function edit($id)
    {
        $booking = Booking::findOrFail($id);
        return view('bookings.edit', compact('booking'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'passenger_id' => 'required|integer|exists:passengers,Passenger_ID',
            'flight_id' => 'required|integer|exists:flights,Flight_ID',
            'booking_date' => 'required|date',
            'status' => 'required|string|max:50',
        ]);
        
        $booking = Booking::findOrFail($id);
        $oldStatus = $booking->Status;
        
        $booking->update([
            'Passenger_ID' => $validated['passenger_id'],
            'Flight_ID' => $validated['flight_id'],
            'Booking_Date' => $validated['booking_date'],
            'Status' => $validated['status'],
        ]);
        
        // If status changed to confirmed, send email notification
        if ($oldStatus !== 'confirmed' && $validated['status'] === 'confirmed') {
            $this->sendBookingConfirmationEmail($booking);
        }
        
        return redirect()->route('admin.bookings.index')->with('success', 'Booking updated successfully.');
    }

    /**
     * Confirm a booking and send email notification
     */
    public function confirmBooking($id)
    {
        $booking = Booking::with(['passenger.user', 'flight.departureAirport', 'flight.arrivalAirport'])->findOrFail($id);
        
        if ($booking->Status !== 'confirmed') {
            $booking->update(['Status' => 'confirmed']);
            $this->sendBookingConfirmationEmail($booking);
            
            return redirect()->route('admin.bookings.index')->with('success', 'Booking confirmed and email notification sent.');
        }
        
        return redirect()->route('admin.bookings.index')->with('info', 'Booking is already confirmed.');
    }

    /**
     * Send booking confirmation email
     */
    private function sendBookingConfirmationEmail($booking)
    {
        try {
            $user = $booking->passenger->user;
            $flight = $booking->flight;
            
            // Calculate pricing for email
            $basePrice = $flight->price ?? 299;
            $taxes = 25;
            $classMultipliers = [
                'economy' => 1.0,
                'premium' => 1.5,
                'business' => 2.5
            ];
            
            $multiplier = $classMultipliers[$booking->seat_class];
            $pricePerPassenger = ($basePrice * $multiplier) + $taxes;
            $totalAmount = $pricePerPassenger * $booking->passenger_count;
            
            // Send email using Laravel's Mail facade and mailable
            Mail::to($user->email)->send(new BookingConfirmationMail($booking, $user, $flight, $totalAmount));
        } catch (\Exception $e) {
            \Log::error('Failed to send booking confirmation email: ' . $e->getMessage());
        }
    }

    public function destroy($id)
    {
        $booking = Booking::findOrFail($id);
        
        // Check if user owns this booking or is admin
        if (auth()->user()->isAdmin() || $booking->passenger->user_id === auth()->id()) {
            $booking->delete();
            return redirect()->route('user.bookings.index')->with('success', 'Booking cancelled successfully.');
        }
        
        return redirect()->route('user.bookings.index')->with('error', 'You cannot cancel this booking.');
    }
}
