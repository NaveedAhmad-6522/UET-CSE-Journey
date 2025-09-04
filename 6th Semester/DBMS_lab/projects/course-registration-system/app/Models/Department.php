<?php
namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use App\Models\Student;
use App\Models\Course;
use App\Models\Instructor;

class Department extends Model
{
    use HasFactory;

    protected $table = 'departments';
    protected $primaryKey = 'department_id';
    public $timestamps = true;

    protected $fillable = [
        'department_name',
        'department_code',
        'faculty',
    ];

    public function students()
    {
        return $this->hasMany(Student::class, 'department_id', 'department_id');
    }

    public function courses()
    {
        return $this->hasMany(Course::class, 'department_id', 'department_id');
    }

    public function instructors()
    {
        return $this->hasMany(Instructor::class, 'department_id', 'department_id');
    }
}