<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Flight;
use App\Models\Airport;

class HomeController extends Controller
{
    /**
     * Show the main homepage
     */
    public function index()
    {
        $flights = Flight::with(['departureAirport', 'arrivalAirport'])
            ->where('Departure_Time', '>', now())
            ->orderBy('Departure_Time')
            ->take(6)
            ->get();

        $airports = Airport::take(8)->get();

        return view('home', compact('flights', 'airports'));
    }

    /**
     * Show about page
     */
    public function about()
    {
        return view('pages.about');
    }

    /**
     * Show contact page
     */
    public function contact()
    {
        return view('pages.contact');
    }

    /**
     * Show user dashboard
     */
    public function dashboard()
    {
        $user = auth()->user();
        
        if ($user->isAdmin()) {
            return redirect('/admin/dashboard');
        }

        $bookings = $user->bookings()->with(['flight', 'payment'])->latest()->take(5)->get();
        
        return view('dashboard', compact('bookings'));
    }

    /**
     * Show flight search page
     */
    public function searchFlights(Request $request)
    {
        $airports = Airport::all();
        $flights = collect();

        if ($request->filled(['from', 'to', 'date'])) {
            $flights = Flight::with(['departureAirport', 'arrivalAirport', 'seats'])
                ->where('Source', $request->from)
                ->where('Destination', $request->to)
                ->whereDate('Departure_Time', $request->date)
                ->where('Departure_Time', '>', now())
                ->get();
        }

        return view('flights.search', compact('flights', 'airports'));
    }

    /**
     * Show flight details
     */
    public function flightDetails($id)
    {
        $flight = Flight::with(['departureAirport', 'arrivalAirport', 'seats', 'staff'])
            ->findOrFail($id);

        return view('flights.details', compact('flight'));
    }
}
