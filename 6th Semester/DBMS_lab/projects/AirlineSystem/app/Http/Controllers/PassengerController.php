<?php

namespace App\Http\Controllers;

use App\Models\Passenger;
use Illuminate\Http\Request;

class PassengerController extends Controller
{
    public function index()
    {
        $passengers = Passenger::with('loyaltyProgram')->get();
        return view('passengers.index', compact('passengers'));
    }

    public function create()
    {
        return view('passengers.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'Name' => 'required|string|max:100',
            'Email' => 'required|email|max:100',
            'Phone' => 'required|string|max:20',
            'Passport_No' => 'required|string|max:50',
            'Loyalty_ID' => 'nullable|exists:loyalty_programs,Loyalty_ID',
        ]);
        Passenger::create($validated);
        return redirect()->route('admin.passengers.index')->with('success', 'Passenger created successfully.');
    }

    public function edit($id)
    {
        $passenger = Passenger::findOrFail($id);
        return view('passengers.edit', compact('passenger'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'Name' => 'required|string|max:100',
            'Email' => 'required|email|max:100',
            'Phone' => 'required|string|max:20',
            'Passport_No' => 'required|string|max:50',
            'Loyalty_ID' => 'nullable|exists:loyalty_programs,Loyalty_ID',
        ]);
        $passenger = Passenger::findOrFail($id);
        $passenger->update($validated);
        return redirect()->route('admin.passengers.index')->with('success', 'Passenger updated successfully.');
    }

    public function destroy($id)
    {
        Passenger::destroy($id);
        return redirect()->route('admin.passengers.index');
    }
}
