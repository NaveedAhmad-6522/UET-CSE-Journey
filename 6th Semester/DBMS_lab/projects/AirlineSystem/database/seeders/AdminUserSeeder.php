<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\User;
use Illuminate\Support\Facades\Hash;

class AdminUserSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        User::create([
            'name' => 'Admin User',
            'email' => 'admin@skyway.com',
            'password' => Hash::make('admin123'),
            'role' => 'admin',
            'phone' => '+1234567890',
            'address' => 'Admin Address',
        ]);

        // Create a sample staff user
        User::create([
            'name' => 'Staff User',
            'email' => 'staff@skyway.com',
            'password' => Hash::make('staff123'),
            'role' => 'staff',
            'phone' => '+1234567891',
            'address' => 'Staff Address',
        ]);

        // Create a sample passenger user
        User::create([
            'name' => 'John Passenger',
            'email' => 'passenger@skyway.com',
            'password' => Hash::make('passenger123'),
            'role' => 'passenger',
            'phone' => '+1234567892',
            'address' => 'Passenger Address',
        ]);
    }
}
