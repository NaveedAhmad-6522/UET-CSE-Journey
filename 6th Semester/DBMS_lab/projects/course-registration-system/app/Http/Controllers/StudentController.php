<?php

namespace App\Http\Controllers;

use App\Models\Student;
use Illuminate\Http\Request;
use Illuminate\Database\Eloquent\ModelNotFoundException;

class StudentController extends Controller
{
    // GET /api/students
    public function index()
    {
        $students = Student::with('department')->get();
        return response()->json($students, 200);
    }

    // GET /api/students/{id}
    public function show($id)
    {
        try {
            $student = Student::with(['department', 'courses'])->findOrFail($id);
            return response()->json($student, 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Student not found'], 404);
        }
    }

    // POST /api/students
    public function store(Request $request)
    {
        $validated = $request->validate([
            'first_name'          => 'required|string|max:255',
            'last_name'           => 'required|string|max:255',
            'email'               => 'required|email|unique:students,email',
            'phone'               => 'required|string|max:20',
            'registration_number' => 'required|string|max:100|unique:students,registration_number',
            'department_id'       => 'required|exists:departments,department_id',
        ]);

        $student = Student::create($validated);

        return response()->json([
            'message' => 'Student created successfully.',
            'student' => $student,
        ], 201);
    }

    // PUT /api/students/{id}
    public function update(Request $request, $id)
    {
        try {
            $student = Student::findOrFail($id);

            $validated = $request->validate([
                'first_name'          => 'sometimes|required|string|max:255',
                'last_name'           => 'sometimes|required|string|max:255',
                'email'               => 'sometimes|required|email|unique:students,email,' . $id . ',student_id',
                'phone'               => 'sometimes|required|string|max:20',
                'registration_number' => 'sometimes|required|string|max:100|unique:students,registration_number,' . $id . ',student_id',
                'department_id'       => 'sometimes|required|exists:departments,department_id',
            ]);

            $student->update($validated);

            return response()->json([
                'message' => 'Student updated successfully.',
                'student' => $student,
            ], 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Student not found'], 404);
        }
    }

    // DELETE /api/students/{id}
    public function destroy($id)
    {
        try {
            $student = Student::findOrFail($id);
            $student->delete();
            return response()->json(['message' => 'Student deleted successfully.'], 204);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Student not found'], 404);
        }
    }
}