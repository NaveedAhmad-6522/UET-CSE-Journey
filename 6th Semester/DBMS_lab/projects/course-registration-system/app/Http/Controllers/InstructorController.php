<?php

namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use App\Models\Instructor;
use Illuminate\Database\Eloquent\ModelNotFoundException;

class InstructorController extends Controller
{
    // List all instructors
    public function index()
    {
        return response()->json(Instructor::all(), 200);
    }

    // Show a specific instructor
    public function show($id)
    {
        try {
            $instructor = Instructor::findOrFail($id);
            return response()->json($instructor, 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Instructor not found'], 404);
        }
    }

    // Create a new instructor
    public function store(Request $request)
    {
        $validated = $request->validate([
            'name'          => 'required|string|max:255',
            'email'         => 'required|email|unique:instructors,email',
            'department_id' => 'nullable|exists:departments,department_id', // optional
        ]);

        $instructor = Instructor::create($validated);
        return response()->json($instructor, 201);
    }

    // Update an existing instructor
    public function update(Request $request, $id)
    {
        try {
            $instructor = Instructor::findOrFail($id);

            $validated = $request->validate([
                'name'          => 'sometimes|string|max:255',
                'email'         => 'sometimes|email|unique:instructors,email,' . $id,
                'department_id' => 'nullable|exists:departments,department_id', // optional
            ]);

            $instructor->update($validated);
            return response()->json($instructor, 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Instructor not found'], 404);
        }
    }

    // Delete an instructor
    public function destroy($id)
    {
        try {
            $instructor = Instructor::findOrFail($id);
            $instructor->delete();
            return response()->json(['message' => 'Instructor deleted'], 204);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Instructor not found'], 404);
        }
    }
}