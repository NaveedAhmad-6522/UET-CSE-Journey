<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use App\Models\Course;
use App\Models\Classroom;
use App\Models\Instructor;

class Schedule extends Model
{
    use HasFactory;

    protected $primaryKey = 'schedule_id';

  protected $fillable = [
    'course_id',
    'instructor_id',
    'classroom_id',
    'day_of_week', // ✅ Use correct column name
    'start_time',
    'end_time',
];

    public function course()
    {
        return $this->belongsTo(Course::class, 'course_id');
    }

    public function classroom()
    {
        return $this->belongsTo(Classroom::class, 'classroom_id');
    }

    public function instructor()
    {
        return $this->belongsTo(Instructor::class, 'instructor_id');
    }
}