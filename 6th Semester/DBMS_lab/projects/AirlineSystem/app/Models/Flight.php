<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Flight extends Model
{
    // Tell Laravel the custom primary key name
    protected $primaryKey = 'Flight_ID';

    // Let Laravel know it's auto-incrementing
    public $incrementing = true;

    // Data type of the primary key
    protected $keyType = 'int';

    // Mass assignable fields
    protected $fillable = [
        'Airline_Name',
        'Source',
        'Destination',
        'Departure_Time',
        'Arrival_Time'
    ];

    // ✅ Corrected: Flight to Booking relationship
    public function bookings()
    {
        return $this->hasMany(Booking::class, 'Flight_ID', 'Flight_ID');
    }

    public function departureAirport()
    {
        return $this->belongsTo(Airport::class, 'Source', 'Airport_ID');
    }

    public function arrivalAirport()
    {
        return $this->belongsTo(Airport::class, 'Destination', 'Airport_ID');
    }

    public function seats()
    {
        return $this->hasMany(Seat::class, 'Flight_ID', 'Flight_ID');
    }

    public function staff()
    {
        return $this->hasMany(Staff::class, 'assigned_flight_id', 'Flight_ID');
    }

    protected $casts = [
        'Departure_Time' => 'datetime:Y-m-d H:i:s',
        'Arrival_Time' => 'datetime:Y-m-d H:i:s',
    ];

    // Add accessor to handle null dates
    public function getDepartureTimeAttribute($value)
    {
        return $value ? \Carbon\Carbon::parse($value) : null;
    }

    public function getArrivalTimeAttribute($value)
    {
        return $value ? \Carbon\Carbon::parse($value) : null;
    }
}
