<?php

namespace App\Http\Controllers;

use App\Models\Department;
use Illuminate\Http\Request;
use Illuminate\Database\Eloquent\ModelNotFoundException;

class DepartmentController extends Controller
{
    // List all departments
    public function index()
    {
        return response()->json(Department::all(), 200);
    }

    // Show a specific department
    public function show($id)
    {
        try {
            $department = Department::findOrFail($id);
            return response()->json($department, 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Department not found'], 404);
        }
    }

    // Create a new department
    public function store(Request $request)
    {
        try {
            $validated = $request->validate([
                'department_name' => 'required|string|unique:departments,department_name',
                'department_code' => 'required|string|unique:departments,department_code',
                'faculty'         => 'nullable|string',
            ]);

            $department = Department::create($validated);
            return response()->json($department, 201);
        } catch (\Exception $e) {
            return response()->json(['error' => $e->getMessage()], 500);
        }
    }

    // Update department info
    public function update(Request $request, $id)
    {
        try {
            $department = Department::findOrFail($id);

            $validated = $request->validate([
                'department_name' => 'sometimes|required|string|unique:departments,department_name,' . $id . ',department_id',
                'department_code' => 'sometimes|required|string|unique:departments,department_code,' . $id . ',department_id',
                'faculty'         => 'nullable|string',
            ]);

            $department->update($validated);
            return response()->json($department, 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Department not found'], 404);
        } catch (\Exception $e) {
            return response()->json(['error' => $e->getMessage()], 500);
        }
    }

    // Delete a department
    public function destroy($id)
    {
        try {
            $department = Department::findOrFail($id);
            $department->delete();
            // 204 No Content should have an empty response body
            return response()->json(null, 204);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Department not found'], 404);
        }
    }
}