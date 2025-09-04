<?php

namespace App\Http\Controllers;

use App\Models\Flight;
use App\Models\Airport;
use Illuminate\Http\Request;

class FlightController extends Controller
{
    public function index()
    {
        $flights = Flight::with(['departureAirport', 'arrivalAirport'])->get();
        return view('flights.index', compact('flights'));
    }

    public function create()
    {
        return view('flights.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'Airline_Name' => 'required|string|max:100',
            'Source' => 'required|exists:airports,Airport_ID',
            'Destination' => 'required|exists:airports,Airport_ID',
            'Departure_Time' => 'required|date',
            'Arrival_Time' => 'required|date|after:Departure_Time',
        ]);
        Flight::create($validated);
        return redirect()->route('admin.flights.index')->with('success', 'Flight created successfully.');
    }

    public function edit($id)
    {
        $flight = Flight::findOrFail($id);
        $airports = Airport::all();
        return view('flights.edit', compact('flight', 'airports'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'Airline_Name' => 'required|string|max:100',
            'Source' => 'required|exists:airports,Airport_ID',
            'Destination' => 'required|exists:airports,Airport_ID',
            'Departure_Time' => 'required|date',
            'Arrival_Time' => 'required|date|after:Departure_Time',
        ]);
        $flight = Flight::findOrFail($id);
        $flight->update($validated);
        return redirect()->route('admin.flights.index')->with('success', 'Flight updated successfully.');
    }

    public function destroy($id)
    {
        $flight = Flight::findOrFail($id);

        // Delete related bookings first
        $flight->bookings()->delete();

        // Then delete the flight
        $flight->delete();

        return redirect()->route('admin.flights.index')->with('success', 'Flight deleted successfully');
    }
}