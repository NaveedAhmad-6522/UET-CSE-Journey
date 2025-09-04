<?php

namespace App\Http\Controllers;

use App\Models\Seat;
use Illuminate\Http\Request;

class SeatController extends Controller
{
    public function index()
    {
        $seats = Seat::with('flight')->get();
        return view('seats.index', compact('seats'));
    }

    public function create()
    {
        return view('seats.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'flight_id' => 'required|integer|exists:flights,Flight_ID',
            'seat_number' => 'required|string|max:10',
            'class' => 'required|string|max:20',
            'availability_status' => 'required|string|max:20',
        ]);
        Seat::create($validated);
        return redirect()->route('admin.seats.index')->with('success', 'Seat created successfully.');
    }

    public function edit($id)
    {
        $seat = Seat::findOrFail($id);
        return view('seats.edit', compact('seat'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'flight_id' => 'required|integer|exists:flights,Flight_ID',
            'seat_number' => 'required|string|max:10',
            'class' => 'required|string|max:20',
            'availability_status' => 'required|string|max:20',
        ]);
        $seat = Seat::findOrFail($id);
        $seat->update($validated);
        return redirect()->route('admin.seats.index')->with('success', 'Seat updated successfully.');
    }

    public function destroy($id)
    {
        Seat::destroy($id);
        return redirect()->route('admin.seats.index');
    }
}