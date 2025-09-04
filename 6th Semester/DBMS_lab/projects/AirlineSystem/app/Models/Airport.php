<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Airport extends Model
{
    protected $fillable = ['Name', 'City', 'Country', 'Code'];
    protected $primaryKey = 'Airport_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function departures()
    {
        return $this->hasMany(Flight::class, 'Source', 'Airport_ID');
    }

    public function arrivals()
    {
        return $this->hasMany(Flight::class, 'Destination', 'Airport_ID');
    }
}
