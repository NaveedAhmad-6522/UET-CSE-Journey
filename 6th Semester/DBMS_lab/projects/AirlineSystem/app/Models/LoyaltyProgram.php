<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class LoyaltyProgram extends Model
{
    protected $fillable = ['Program_Name', 'Miles_Earned', 'Membership_Level'];
    protected $primaryKey = 'Loyalty_ID';
    public $incrementing = true;
    protected $keyType = 'int';

    public function passengers()
    {
        return $this->hasMany(Passenger::class, 'Loyalty_ID');
    }
}
