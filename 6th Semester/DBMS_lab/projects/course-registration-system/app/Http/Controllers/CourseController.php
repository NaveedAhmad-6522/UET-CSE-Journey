<?php

namespace App\Http\Controllers;

use App\Models\Course;
use Illuminate\Http\Request;

class CourseController extends Controller
{
    /**
     * Display a listing of courses with related instructor and department.
     */
    public function index()
    {
        $courses = Course::with(['instructor', 'department'])->get();
        return response()->json($courses);
    }

    /**
     * Store a newly created course.
     */
    public function store(Request $request)
    {
        $validated = $request->validate([
            'course_code' => 'required|unique:courses,course_code',
            'course_name' => 'required',
            'credit_hours' => 'required|integer',
            'instructor_id' => 'required|exists:instructors,instructor_id',
            'department_id' => 'required|exists:departments,department_id',
        ]);
    
        $course = Course::create($validated)->load(['instructor', 'department']);
    
        return response()->json([
            'message' => 'Course created successfully.',
            'course' => $course
        ], 201);
    }

    /**
     * Display the specified course.
     */
    public function show($id)
    {
        $course = Course::with(['instructor', 'department'])->findOrFail($id);
        return response()->json($course);
    }

    /**
     * Update the specified course.
     */
    public function update(Request $request, $id)
{
    $course = Course::findOrFail($id);

    $validated = $request->validate([
        'course_code' => "required|unique:courses,course_code,{$id},course_id",
        'course_name' => 'required',
        'credit_hours' => 'required|integer',
        'instructor_id' => 'required|exists:instructors,instructor_id',
        'department_id' => 'required|exists:departments,department_id',
    ]);

    $course->update($validated);
    $course->load(['instructor', 'department']);

    return response()->json([
        'message' => 'Course updated successfully.',
        'course' => $course
    ]);
}

    /**
     * Remove the specified course.
     */
    public function destroy($id)
    {
        $course = Course::findOrFail($id);
        $course->delete();

        return response()->json(['message' => 'Course deleted successfully.']);
    }
}


