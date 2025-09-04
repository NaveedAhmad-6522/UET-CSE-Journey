<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\User;
use App\Models\Passenger;

class LinkUsersToPassengersSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        // Get all users
        $users = User::all();

        foreach ($users as $user) {
            // Check if passenger record exists for this user
            $passenger = Passenger::where('user_id', $user->id)->first();
            
            if (!$passenger) {
                // Create passenger record for this user
                Passenger::create([
                    'user_id' => $user->id,
                    'Name' => $user->name,
                    'Email' => $user->email,
                    'Phone' => $user->phone ?? 'N/A',
                    'Passport_No' => 'PASS-' . $user->id . '-' . time(),
                    'Loyalty_ID' => null,
                ]);
            }
        }

        // Handle existing passengers that don't have user_id
        $orphanedPassengers = Passenger::whereNull('user_id')->get();
        
        foreach ($orphanedPassengers as $passenger) {
            // Check if a user already exists with this email
            $existingUser = User::where('email', $passenger->Email)->first();
            
            if ($existingUser) {
                // Update passenger with existing user_id
                $passenger->update(['user_id' => $existingUser->id]);
            } else {
                // Create a new user for this passenger
                $user = User::create([
                    'name' => $passenger->Name,
                    'email' => $passenger->Email ?? 'passenger' . $passenger->Passenger_ID . '@skyway.com',
                    'password' => bcrypt('password123'),
                    'role' => 'passenger',
                    'phone' => $passenger->Phone ?? 'N/A',
                    'address' => 'Address not provided',
                ]);

                // Update passenger with user_id
                $passenger->update(['user_id' => $user->id]);
            }
        }
    }
}
