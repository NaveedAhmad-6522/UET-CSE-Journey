<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\StudentController;
use App\Http\Controllers\CourseController;
use App\Http\Controllers\DepartmentController;
use App\Http\Controllers\ScheduleController;
use App\Http\Controllers\InstructorController;
use App\Http\Controllers\ClassroomController;
use App\Http\Controllers\EnrollmentController;

Route::apiResource('students', StudentController::class);
Route::apiResource('courses', CourseController::class);
Route::apiResource('departments', DepartmentController::class);
Route::apiResource('schedules', ScheduleController::class);
Route::apiResource('instructors', InstructorController::class);
Route::apiResource('classrooms', ClassroomController::class);
Route::apiResource('enrollments', EnrollmentController::class);
Route::post('/apply', [EnrollmentController::class, 'publicApply']);
// routes/web.php


Route::get('/', function () {
    return response()->json(['message' => 'Laravel backend is working!']);
});