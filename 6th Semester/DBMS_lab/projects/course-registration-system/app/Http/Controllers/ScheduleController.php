<?php

namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use App\Models\Schedule;
use Illuminate\Database\Eloquent\ModelNotFoundException;

class ScheduleController extends Controller
{
    // GET /api/schedules
    public function index()
    {
        return response()->json(
            Schedule::with([
                'course.department',
                'instructor',
                'classroom.department',
            ])->get(),
            200
        );
    }

    // POST /api/schedules
public function store(Request $request)
{
    $validated = $request->validate([
        'day' => 'required|string',
        'start_time' => 'required',
        'end_time' => 'required|after:start_time',
        'course_id' => 'required|exists:courses,course_id',
        'classroom_id' => 'required|exists:classrooms,classroom_id',
        'instructor_id' => 'required|exists:instructors,instructor_id', // ✅ Add this
    ]);

    $data = $validated;
    $data['day_of_week'] = $data['day'];
    unset($data['day']);

    $schedule = Schedule::create($data);

    return response()->json([
        'message' => 'Schedule created successfully.',
        'schedule' => $schedule
    ], 201);
}

    // GET /api/schedules/{id}
    public function show($id)
    {
        try {
            $schedule = Schedule::with(['course', 'instructor', 'classroom'])->findOrFail($id);
            return response()->json($schedule, 200);
        } catch (ModelNotFoundException $e) {
            return response()->json(['error' => 'Schedule not found'], 404);
        }
    }

    // PUT or PATCH /api/schedules/{id}
    public function update(Request $request, $id)
    {
        $schedule = Schedule::findOrFail($id);

     $validated = $request->validate([
    'day' => 'required|string',
    'start_time' => 'required',
    'end_time' => 'required|after:start_time',
    'course_id' => 'required|exists:courses,course_id',
    'classroom_id' => 'required|exists:classrooms,classroom_id',
    'instructor_id' => 'required|exists:instructors,instructor_id', // <-- Add this if needed
]);

        $schedule->update($validated);

        return response()->json([
            'message'  => 'Schedule updated successfully.',
            'schedule' => $schedule
        ], 200);
    }

    // DELETE /api/schedules/{id}
    public function destroy($id)
    {
        $schedule = Schedule::findOrFail($id);
        $schedule->delete();

        return response()->json(['message' => 'Schedule deleted successfully.'], 204);
    }
}