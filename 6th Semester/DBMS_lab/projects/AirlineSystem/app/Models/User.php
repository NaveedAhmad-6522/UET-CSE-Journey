<?php

namespace App\Models;

// use Illuminate\Contracts\Auth\MustVerifyEmail;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Foundation\Auth\User as Authenticatable;
use Illuminate\Notifications\Notifiable;

class User extends Authenticatable
{
    /** @use HasFactory<\Database\Factories\UserFactory> */
    use HasFactory, Notifiable;

    /**
     * The attributes that are mass assignable.
     *
     * @var list<string>
     */
    protected $fillable = [
        'name',
        'email',
        'password',
        'role',
        'phone',
        'address',
    ];

    /**
     * The attributes that should be hidden for serialization.
     *
     * @var list<string>
     */
    protected $hidden = [
        'password',
        'remember_token',
    ];

    /**
     * Get the attributes that should be cast.
     *
     * @return array<string, string>
     */
    protected function casts(): array
    {
        return [
            'email_verified_at' => 'datetime',
            'password' => 'hashed',
        ];
    }

    /**
     * Check if user is admin
     */
    public function isAdmin(): bool
    {
        return $this->role === 'admin';
    }

    /**
     * Check if user is staff
     */
    public function isStaff(): bool
    {
        return $this->role === 'staff';
    }

    /**
     * Check if user is passenger
     */
    public function isPassenger(): bool
    {
        return $this->role === 'passenger';
    }

    /**
     * Get passenger profile
     */
    public function passenger()
    {
        return $this->hasOne(Passenger::class);
    }

    /**
     * Get staff profile
     */
    public function staff()
    {
        return $this->hasOne(Staff::class);
    }

    /**
     * Get bookings for this user
     */
    public function bookings()
    {
        return $this->hasManyThrough(Booking::class, Passenger::class, 'user_id', 'Passenger_ID', 'id', 'Passenger_ID');
    }
}
