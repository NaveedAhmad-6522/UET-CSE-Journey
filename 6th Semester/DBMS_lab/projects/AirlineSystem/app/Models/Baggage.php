<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Baggage extends Model
{
    protected $fillable = ['Booking_ID', 'Weight', 'Baggage_Tag', 'Baggage_Status'];
    protected $primaryKey = 'Baggage_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function booking()
    {
        return $this->belongsTo(Booking::class, 'Booking_ID', 'Booking_ID');
    }
}
