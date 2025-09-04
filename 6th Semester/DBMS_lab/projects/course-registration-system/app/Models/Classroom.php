<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use App\Models\Schedule;
use App\Models\Department; // ✅ Add this line

class Classroom extends Model
{
    use HasFactory;

    protected $primaryKey = 'classroom_id';

    protected $fillable = [
        'room_number',
        'building_name',
        'capacity',
        'department_id', // ✅ Make sure this is fillable too
    ];

    public function schedules()
    {
        return $this->hasMany(Schedule::class, 'classroom_id');
    }

    public function department()
    {
        return $this->belongsTo(Department::class, 'department_id'); // ✅ This is required
    }
}