<?php

namespace App\Http\Controllers;

use App\Models\Airport;
use Illuminate\Http\Request;

class AirportController extends Controller
{
    public function index()
    {
        $airports = Airport::all();
        return view('airports.index', compact('airports'));
    }

    public function create()
    {
        return view('airports.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'name' => 'required|string|max:100',
            'city' => 'required|string|max:100',
            'country' => 'required|string|max:100',
            'code' => 'required|string|max:10|unique:airports,Code',
        ]);
        
        Airport::create([
            'Name' => $validated['name'],
            'City' => $validated['city'],
            'Country' => $validated['country'],
            'Code' => $validated['code'],
        ]);
        
        return redirect()->route('admin.airports.index')->with('success', 'Airport created successfully.');
    }

    public function edit($id)
    {
        $airport = Airport::findOrFail($id);
        return view('airports.edit', compact('airport'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'name' => 'required|string|max:100',
            'city' => 'required|string|max:100',
            'country' => 'required|string|max:100',
            'code' => 'required|string|max:10|unique:airports,Code,' . $id . ',Airport_ID',
        ]);
        
        $airport = Airport::findOrFail($id);
        $airport->update([
            'Name' => $validated['name'],
            'City' => $validated['city'],
            'Country' => $validated['country'],
            'Code' => $validated['code'],
        ]);
        
        return redirect()->route('admin.airports.index')->with('success', 'Airport updated successfully.');
    }

    public function destroy($id)
    {
        Airport::destroy($id);
        return redirect()->route('admin.airports.index');
    }
}