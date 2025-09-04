<?php

namespace App\Http\Controllers;

use App\Models\Staff;
use Illuminate\Http\Request;

class StaffController extends Controller
{
    public function index()
    {
        $staff = Staff::with('flight')->get();
        return view('staff.index', compact('staff'));
    }

    public function create()
    {
        return view('staff.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'name' => 'required|string|max:100',
            'role' => 'required|string|max:50',
            'contact_number' => 'required|string|max:20',
            'assigned_flight_id' => 'nullable|integer|exists:flights,Flight_ID',
        ]);
        
        // Map form fields to database columns
        Staff::create([
            'Name' => $validated['name'],
            'Role' => $validated['role'],
            'Contact_Number' => $validated['contact_number'],
            'Assigned_Flight_ID' => $validated['assigned_flight_id'],
        ]);
        
        return redirect()->route('admin.staff.index')->with('success', 'Staff created successfully.');
    }

    public function edit($id)
    {
        $staff = Staff::findOrFail($id);
        return view('staff.edit', compact('staff'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'name' => 'required|string|max:100',
            'role' => 'required|string|max:50',
            'contact_number' => 'required|string|max:20',
            'assigned_flight_id' => 'nullable|integer|exists:flights,Flight_ID',
        ]);
        
        $staff = Staff::findOrFail($id);
        
        // Map form fields to database columns
        $staff->update([
            'Name' => $validated['name'],
            'Role' => $validated['role'],
            'Contact_Number' => $validated['contact_number'],
            'Assigned_Flight_ID' => $validated['assigned_flight_id'],
        ]);
        
        return redirect()->route('admin.staff.index')->with('success', 'Staff updated successfully.');
    }

    public function destroy($id)
    {
        Staff::destroy($id);
        return redirect()->route('admin.staff.index')->with('success', 'Staff deleted successfully.');
    }
}
