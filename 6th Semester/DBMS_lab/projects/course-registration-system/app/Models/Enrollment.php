<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use App\Models\Student;
use App\Models\Course;

class Enrollment extends Model
{
    use HasFactory;

    protected $primaryKey = 'enrollment_id';
protected $fillable = [
    'student_id',
    'course_id',
    'enrolled_on',
    'status',
    'semester',
];

    protected $casts = [
        'enrolled_on' => 'date',
    ];

    // Relationship: Each enrollment belongs to a student
    public function student()
    {
        return $this->belongsTo(Student::class, 'student_id', 'student_id');
    }

    // Relationship: Each enrollment belongs to a course
    public function course()
    {
        return $this->belongsTo(Course::class, 'course_id', 'course_id');
    }
}