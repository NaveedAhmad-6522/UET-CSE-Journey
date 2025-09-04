<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Seat extends Model
{
    protected $fillable = ['flight_id', 'seat_number', 'class', 'availability_status'];
    protected $primaryKey = 'Seat_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function flight()
    {
        return $this->belongsTo(Flight::class);
    }
}
