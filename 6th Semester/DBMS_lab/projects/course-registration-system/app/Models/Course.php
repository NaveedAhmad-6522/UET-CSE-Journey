<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;

use App\Models\Instructor;
use App\Models\Department;
use App\Models\Enrollment;
use App\Models\Student;
use App\Models\Schedule;

class Course extends Model
{
    use HasFactory;

    protected $primaryKey = 'course_id';

    protected $fillable = [
        'course_code',
        'course_name',
        'credit_hours',
        'instructor_id',
        'department_id',
    ];

    // Relationship: Course belongs to Instructor
    public function instructor()
    {
        return $this->belongsTo(Instructor::class, 'instructor_id', 'instructor_id');
    }

    // Relationship: Course belongs to Department
    public function department()
    {
        return $this->belongsTo(Department::class, 'department_id', 'department_id');
    }

    // Relationship: Course has many Enrollments
    public function enrollments()
    {
        return $this->hasMany(Enrollment::class, 'course_id', 'course_id');
    }

    // Relationship: Course belongs to many Students through Enrollments pivot table
    public function students()
    {
        return $this->belongsToMany(Student::class, 'enrollments', 'course_id', 'student_id');
    }

    // Relationship: Course has many Schedules
    public function schedules()
    {
        return $this->hasMany(Schedule::class, 'course_id', 'course_id');
    }
}