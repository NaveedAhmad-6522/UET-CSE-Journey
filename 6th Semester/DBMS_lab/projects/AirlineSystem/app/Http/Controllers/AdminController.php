<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Flight;
use App\Models\Booking;
use App\Models\Passenger;
use App\Models\Payment;
use App\Models\Staff;
use App\Models\Airport;
use App\Models\LoyaltyProgram;
use App\Models\Baggage;

class AdminController extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
        $this->middleware('admin');
    }

    /**
     * Show admin dashboard
     */
    public function dashboard()
    {
        try {
            $stats = [
                'total_flights' => Flight::count(),
                'total_bookings' => Booking::count(),
                'total_passengers' => Passenger::count(),
                'total_revenue' => Payment::sum('Amount') ?? 0,
                'upcoming_flights' => Flight::where('Departure_Time', '>', now())->count(),
                'pending_payments' => Payment::where('status', 'pending')->count(),
            ];

            $recent_bookings = Booking::with(['passenger.user', 'flight'])
                ->latest()
                ->take(10)
                ->get();

            $upcoming_flights = Flight::with(['departureAirport', 'arrivalAirport'])
                ->where('Departure_Time', '>', now())
                ->orderBy('Departure_Time')
                ->take(5)
                ->get();

            return view('admin.dashboard', compact('stats', 'recent_bookings', 'upcoming_flights'));
        } catch (\Exception $e) {
            // Log the error and return a simple error view
            \Log::error('Admin dashboard error: ' . $e->getMessage());
            
            $stats = [
                'total_flights' => 0,
                'total_bookings' => 0,
                'total_passengers' => 0,
                'total_revenue' => 0,
                'upcoming_flights' => 0,
                'pending_payments' => 0,
            ];
            
            return view('admin.dashboard', compact('stats', 'recent_bookings', 'upcoming_flights'))
                ->with('error', 'Unable to load dashboard data. Please check the database.');
        }
    }

    /**
     * Show admin profile
     */
    public function profile()
    {
        $user = auth()->user();
        return view('admin.profile', compact('user'));
    }

    /**
     * Update admin profile
     */
    public function updateProfile(Request $request)
    {
        $user = auth()->user();
        
        $request->validate([
            'name' => 'required|string|max:255',
            'email' => 'required|email|unique:users,email,' . $user->id,
            'phone' => 'nullable|string|max:20',
            'address' => 'nullable|string|max:500',
        ]);

        $user->update($request->only(['name', 'email', 'phone', 'address']));

        return back()->with('success', 'Profile updated successfully!');
    }
}
