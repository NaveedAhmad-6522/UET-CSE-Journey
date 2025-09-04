<?php

namespace App\Http\Controllers;

use App\Models\LoyaltyProgram;
use Illuminate\Http\Request;

class LoyaltyProgramController extends Controller
{
    public function index()
    {
        $loyaltyPrograms = LoyaltyProgram::all();
        return view('loyalty_programs.index', compact('loyaltyPrograms'));
    }

    public function create()
    {
        return view('loyalty_programs.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'program_name' => 'required|string|max:100',
            'miles_earned' => 'required|integer|min:0',
            'membership_level' => 'required|string|max:50',
        ]);
        LoyaltyProgram::create([
            'Program_Name' => $validated['program_name'],
            'Miles_Earned' => $validated['miles_earned'],
            'Membership_Level' => $validated['membership_level'],
        ]);
        return redirect()->route('admin.loyalty_programs.index')->with('success', 'Loyalty Program created successfully.');
    }

    public function edit($id)
    {
        $loyaltyProgram = LoyaltyProgram::findOrFail($id);
        return view('loyalty_programs.edit', compact('loyaltyProgram'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'program_name' => 'required|string|max:100',
            'miles_earned' => 'required|integer|min:0',
            'membership_level' => 'required|string|max:50',
        ]);
        $loyaltyProgram = LoyaltyProgram::findOrFail($id);
        $loyaltyProgram->update([
            'Program_Name' => $validated['program_name'],
            'Miles_Earned' => $validated['miles_earned'],
            'Membership_Level' => $validated['membership_level'],
        ]);
        return redirect()->route('admin.loyalty_programs.index')->with('success', 'Loyalty Program updated successfully.');
    }

    public function destroy($id)
    {
        LoyaltyProgram::destroy($id);
        return redirect()->route('admin.loyalty_programs.index')->with('success', 'Loyalty Program deleted successfully.');
    }
}
