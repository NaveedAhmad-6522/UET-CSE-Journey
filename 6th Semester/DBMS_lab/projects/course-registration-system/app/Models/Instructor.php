<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;

class Instructor extends Model
{
    use HasFactory;

    // Specify primary key if not 'id'
    protected $primaryKey = 'instructor_id';

    // If your table doesn't use Laravel's timestamps, set this to false
    public $timestamps = true;

    // Mass assignable fields
    protected $fillable = [
        'name',
        'email',
        'department_id',
    ];

    // Relationship to Department model
    public function department()
    {
        // 'department_id' on Instructor links to 'department_id' on Department
        return $this->belongsTo(Department::class, 'department_id', 'department_id');
    }

    // Relationship to Course model (one instructor has many courses)
    public function courses()
    {
        // 'instructor_id' on Course links to 'instructor_id' on Instructor
        return $this->hasMany(Course::class, 'instructor_id', 'instructor_id');
    }
}