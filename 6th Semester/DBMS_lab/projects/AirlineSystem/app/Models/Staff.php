<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Staff extends Model
{
    protected $fillable = ['Name', 'Role', 'Contact_Number', 'Assigned_Flight_ID'];
    protected $primaryKey = 'Staff_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function flight()
    {
        return $this->belongsTo(Flight::class, 'Assigned_Flight_ID', 'Flight_ID');
    }
}
