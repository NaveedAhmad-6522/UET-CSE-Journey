<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use App\Models\Department;
use App\Models\Enrollment;
use App\Models\Course;

class Student extends Model
{
    use HasFactory;

    protected $primaryKey = 'student_id';

  protected $fillable = [
    'first_name',
    'last_name',
    'email',
    'phone',
    'registration_number', // ✅ add this
    'department_id',
];

    // A student belongs to one department
    public function department()
    {
        return $this->belongsTo(Department::class, 'department_id');
    }

    // A student can have many enrollments (pivot table records)
    public function enrollments()
    {
        return $this->hasMany(Enrollment::class, 'student_id', 'student_id');
    }

    // A student can be enrolled in many courses through enrollments
    public function courses()
    {
        return $this->belongsToMany(Course::class, 'enrollments', 'student_id', 'course_id')
                    ->withTimestamps()
                    ->withPivot('enrolled_on');
    }
}