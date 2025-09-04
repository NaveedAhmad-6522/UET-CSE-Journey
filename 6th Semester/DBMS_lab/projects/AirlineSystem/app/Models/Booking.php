<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Booking extends Model
{
    protected $fillable = [
        'Passenger_ID', 
        'Flight_ID', 
        'Booking_Date', 
        'Status',
        'passenger_count',
        'seat_class'
    ];
    protected $primaryKey = 'Booking_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function passenger()
    {
        return $this->belongsTo(Passenger::class, 'Passenger_ID', 'Passenger_ID');
    }

    public function flight()
    {
        return $this->belongsTo(Flight::class, 'Flight_ID', 'Flight_ID');
    }

    public function payment()
    {
        return $this->hasOne(Payment::class, 'Booking_ID', 'Booking_ID');
    }

    public function baggage()
    {
        return $this->hasMany(Baggage::class, 'Booking_ID', 'Booking_ID');
    }
}
