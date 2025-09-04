<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Payment extends Model
{
    protected $fillable = [
        'Booking_ID', 
        'Amount', 
        'Payment_Date', 
        'Payment_Method',
        'status'
    ];
    protected $primaryKey = 'Payment_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function booking()
    {
        return $this->belongsTo(Booking::class, 'Booking_ID', 'Booking_ID');
    }
}
