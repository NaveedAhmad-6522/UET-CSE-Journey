<?php

namespace App\Http\Controllers;

use App\Models\Baggage;
use Illuminate\Http\Request;

class BaggageController extends Controller
{
    public function index()
    {
        $baggage = Baggage::with('booking')->get();
        return view('baggage.index', compact('baggage'));
    }

    public function create()
    {
        return view('baggage.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'booking_id' => 'required|integer|exists:bookings,Booking_ID',
            'weight' => 'required|numeric|min:0',
            'baggage_tag' => 'required|string|max:50',
            'baggage_status' => 'required|string|max:50',
        ]);
        Baggage::create([
            'Booking_ID' => $validated['booking_id'],
            'Weight' => $validated['weight'],
            'Baggage_Tag' => $validated['baggage_tag'],
            'Baggage_Status' => $validated['baggage_status'],
        ]);
        
        // Check if we're in admin context and redirect accordingly
        if (request()->is('admin/*')) {
            return redirect()->route('admin.baggage.index')->with('success', 'Baggage created successfully.');
        } else {
            return redirect()->route('user.baggage.index')->with('success', 'Baggage created successfully.');
        }
    }

    public function edit($id)
    {
        $baggage = Baggage::findOrFail($id);
        return view('baggage.edit', compact('baggage'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'booking_id' => 'required|integer|exists:bookings,Booking_ID',
            'weight' => 'required|numeric|min:0',
            'baggage_tag' => 'required|string|max:50',
            'baggage_status' => 'required|string|max:50',
        ]);
        $baggage = Baggage::findOrFail($id);
        $baggage->update([
            'Booking_ID' => $validated['booking_id'],
            'Weight' => $validated['weight'],
            'Baggage_Tag' => $validated['baggage_tag'],
            'Baggage_Status' => $validated['baggage_status'],
        ]);
        
        // Check if we're in admin context and redirect accordingly
        if (request()->is('admin/*')) {
            return redirect()->route('admin.baggage.index')->with('success', 'Baggage updated successfully.');
        } else {
            return redirect()->route('user.baggage.index')->with('success', 'Baggage updated successfully.');
        }
    }

    public function destroy($id)
    {
        Baggage::destroy($id);
        
        // Check if we're in admin context and redirect accordingly
        if (request()->is('admin/*')) {
            return redirect()->route('admin.baggage.index')->with('success', 'Baggage deleted successfully.');
        } else {
            return redirect()->route('user.baggage.index')->with('success', 'Baggage deleted successfully.');
        }
    }
}
