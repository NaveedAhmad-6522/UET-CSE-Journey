<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Enrollment;
use App\Models\Student;
use Illuminate\Support\Facades\Validator;

class EnrollmentController extends Controller
{
    // ✅ List all enrollments (with optional status filtering)
    public function index(Request $request)
    {
        $status = $request->query('status');

        $query = Enrollment::with(['student', 'course']);

        if ($status) {
            $query->where('status', $status);
        }

        return $query->get();
    }

    // ✅ Store a new enrollment (admin use)
    public function store(Request $request)
    {
        $validated = $request->validate([
            'student_id' => 'required|exists:students,student_id',
            'course_id' => 'required|exists:courses,course_id',
            'enrolled_on' => 'nullable|date',
            'status' => 'nullable|string',
            'semester' => 'nullable|string',
        ]);

        return Enrollment::create($validated);
    }

    // ✅ Update enrollment (status or semester)
    public function update(Request $request, $id)
    {
        $enrollment = Enrollment::findOrFail($id);

        $validated = $request->validate([
            'status' => 'nullable|string|in:pending,approved,rejected',
            'semester' => 'nullable|string',
        ]);

        $enrollment->update($validated);

        return response()->json(['message' => 'Updated successfully']);
    }

    // ✅ Delete enrollment
    public function destroy($id)
    {
        Enrollment::findOrFail($id)->delete();
        return response()->noContent();
    }

    // ✅ Public user applies for a course
    public function publicApply(Request $request)
    {
        $validator = Validator::make($request->all(), [
            'first_name' => 'required|string|max:255',
            'last_name' => 'required|string|max:255',
            'registration_number' => 'required|string|max:100',
            'email' => 'required|email',
            'phone' => 'required|string|max:255',
            'department_id' => 'required|exists:departments,department_id',
            'course_id' => 'required|exists:courses,course_id',
            'semester' => 'nullable|string',
        ]);

        if ($validator->fails()) {
            return response()->json(['errors' => $validator->errors()], 422);
        }

        // 🔍 1. Check if student already exists by registration number
        $student = Student::where('registration_number', $request->registration_number)->first();

        // 🧾 2. If not, create a new student
        if (!$student) {
            $student = Student::create([
                'first_name' => $request->first_name,
                'last_name' => $request->last_name,
                'registration_number' => $request->registration_number,
                'email' => $request->email,
                'phone' => $request->phone,
                'department_id' => $request->department_id,
            ]);
        }

        // ❌ 3. Check if already enrolled in this course
        $alreadyEnrolled = Enrollment::where('student_id', $student->student_id)
            ->where('course_id', $request->course_id)
            ->exists();

        if ($alreadyEnrolled) {
            return response()->json([
                'message' => 'Student is already enrolled in this course.',
            ], 409); // Conflict
        }

        // ✅ 4. Create enrollment record
        $enrollment = Enrollment::create([
            'student_id' => $student->student_id,
            'course_id' => $request->course_id,
            'enrolled_on' => now(),
            'status' => 'pending',
            'semester' => $request->semester ?? null,
        ]);

        return response()->json([
            'message' => 'Application submitted successfully.',
            'student' => $student,
            'enrollment' => $enrollment,
        ], 201);
    }
}
