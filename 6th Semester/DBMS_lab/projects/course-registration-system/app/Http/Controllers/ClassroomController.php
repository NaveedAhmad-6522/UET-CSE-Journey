<?php
// ClassroomController.php
namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use App\Models\Classroom;

class ClassroomController extends Controller
{
    public function index()
    {
       return response()->json(Classroom::with('department')->get(), 200);
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'room_number' => 'required|string|unique:classrooms,room_number',
            'capacity' => 'required|integer',
            'department_id' => 'required|exists:departments,department_id',
        ]);

        $classroom = Classroom::create($validated);
        return response()->json($classroom, 201);
    }

    public function show($id)
    {
        $classroom = Classroom::findOrFail($id);
        return response()->json($classroom, 200);
    }

    public function update(Request $request, $id)
    {
        $classroom = Classroom::findOrFail($id);
        $validated = $request->validate([
            'room_number' => 'sometimes|string|unique:classrooms,room_number,' . $id . ',classroom_id',
            'capacity' => 'sometimes|integer',
            'department_id' => 'required|exists:departments,department_id',
        ]);

        $classroom->update($validated);
        return response()->json($classroom, 200);
    }

    public function destroy($id)
    {
        Classroom::findOrFail($id)->delete();
        return response()->noContent();
    }
}