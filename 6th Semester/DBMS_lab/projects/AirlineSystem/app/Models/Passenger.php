<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Passenger extends Model
{
    protected $fillable = [
        'user_id',
        'Name',
        'Email',
        'Phone',
        'Passport_No',
        'Loyalty_ID'
    ];

    protected $primaryKey = 'Passenger_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function user()
    {
        return $this->belongsTo(User::class, 'user_id', 'id');
    }

    public function bookings()
    {
        return $this->hasMany(Booking::class, 'Passenger_ID', 'Passenger_ID');
    }

    public function loyaltyProgram()
    {
        return $this->belongsTo(LoyaltyProgram::class, 'Loyalty_ID', 'Loyalty_ID');
    }
}
