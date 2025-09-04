<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\Airport;
use App\Models\Flight;
use App\Models\Staff;
use App\Models\LoyaltyProgram;
use App\Models\Baggage;
use App\Models\Booking;
use App\Models\Passenger;
use Carbon\Carbon;

class SampleDataSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        // Create sample airports
        $airports = [
            ['Name' => 'John F. Kennedy International Airport', 'City' => 'New York', 'Country' => 'USA', 'Code' => 'JFK'],
            ['Name' => 'Los Angeles International Airport', 'City' => 'Los Angeles', 'Country' => 'USA', 'Code' => 'LAX'],
            ['Name' => 'O\'Hare International Airport', 'City' => 'Chicago', 'Country' => 'USA', 'Code' => 'ORD'],
            ['Name' => 'Dallas/Fort Worth International Airport', 'City' => 'Dallas', 'Country' => 'USA', 'Code' => 'DFW'],
            ['Name' => 'Denver International Airport', 'City' => 'Denver', 'Country' => 'USA', 'Code' => 'DEN'],
            ['Name' => 'San Francisco International Airport', 'City' => 'San Francisco', 'Country' => 'USA', 'Code' => 'SFO'],
            ['Name' => 'Seattle-Tacoma International Airport', 'City' => 'Seattle', 'Country' => 'USA', 'Code' => 'SEA'],
            ['Name' => 'Miami International Airport', 'City' => 'Miami', 'Country' => 'USA', 'Code' => 'MIA'],
        ];

        foreach ($airports as $airportData) {
            Airport::create($airportData);
        }

        // Create sample flights
        $flights = [
            [
                'Airline_Name' => 'SkyWay Airlines',
                'Source' => 1, // JFK
                'Destination' => 2, // LAX
                'Departure_Time' => Carbon::now()->addDays(1)->setTime(8, 0),
                'Arrival_Time' => Carbon::now()->addDays(1)->setTime(11, 30),
            ],
            [
                'Airline_Name' => 'SkyWay Airlines',
                'Source' => 2, // LAX
                'Destination' => 1, // JFK
                'Departure_Time' => Carbon::now()->addDays(1)->setTime(14, 0),
                'Arrival_Time' => Carbon::now()->addDays(1)->setTime(22, 30),
            ],
            [
                'Airline_Name' => 'SkyWay Airlines',
                'Source' => 3, // ORD
                'Destination' => 4, // DFW
                'Departure_Time' => Carbon::now()->addDays(2)->setTime(9, 0),
                'Arrival_Time' => Carbon::now()->addDays(2)->setTime(11, 0),
            ],
            [
                'Airline_Name' => 'SkyWay Airlines',
                'Source' => 4, // DFW
                'Destination' => 5, // DEN
                'Departure_Time' => Carbon::now()->addDays(2)->setTime(13, 0),
                'Arrival_Time' => Carbon::now()->addDays(2)->setTime(14, 30),
            ],
            [
                'Airline_Name' => 'SkyWay Airlines',
                'Source' => 6, // SFO
                'Destination' => 7, // SEA
                'Departure_Time' => Carbon::now()->addDays(3)->setTime(10, 0),
                'Arrival_Time' => Carbon::now()->addDays(3)->setTime(11, 45),
            ],
            [
                'Airline_Name' => 'SkyWay Airlines',
                'Source' => 8, // MIA
                'Destination' => 1, // JFK
                'Departure_Time' => Carbon::now()->addDays(3)->setTime(16, 0),
                'Arrival_Time' => Carbon::now()->addDays(3)->setTime(19, 0),
            ],
        ];

        foreach ($flights as $flightData) {
            Flight::create($flightData);
        }

        // Create sample staff
        $staff = [
            [
                'Name' => 'John Smith',
                'Role' => 'Pilot',
                'Contact_Number' => '+1-555-0101',
                'Assigned_Flight_ID' => 1,
            ],
            [
                'Name' => 'Sarah Johnson',
                'Role' => 'Flight Attendant',
                'Contact_Number' => '+1-555-0102',
                'Assigned_Flight_ID' => 1,
            ],
            [
                'Name' => 'Michael Brown',
                'Role' => 'Pilot',
                'Contact_Number' => '+1-555-0103',
                'Assigned_Flight_ID' => 2,
            ],
            [
                'Name' => 'Emily Davis',
                'Role' => 'Flight Attendant',
                'Contact_Number' => '+1-555-0104',
                'Assigned_Flight_ID' => 2,
            ],
            [
                'Name' => 'David Wilson',
                'Role' => 'Ground Staff',
                'Contact_Number' => '+1-555-0105',
                'Assigned_Flight_ID' => null,
            ],
            [
                'Name' => 'Lisa Anderson',
                'Role' => 'Customer Service',
                'Contact_Number' => '+1-555-0106',
                'Assigned_Flight_ID' => null,
            ],
        ];

        foreach ($staff as $staffData) {
            Staff::create($staffData);
        }

        // Create sample loyalty programs
        $loyaltyPrograms = [
            [
                'Program_Name' => 'SkyWay Elite',
                'Miles_Earned' => 50000,
                'Membership_Level' => 'Platinum',
            ],
            [
                'Program_Name' => 'SkyWay Gold',
                'Miles_Earned' => 25000,
                'Membership_Level' => 'Gold',
            ],
            [
                'Program_Name' => 'SkyWay Silver',
                'Miles_Earned' => 10000,
                'Membership_Level' => 'Silver',
            ],
            [
                'Program_Name' => 'SkyWay Basic',
                'Miles_Earned' => 5000,
                'Membership_Level' => 'Bronze',
            ],
        ];

        foreach ($loyaltyPrograms as $programData) {
            LoyaltyProgram::create($programData);
        }

        // Create sample baggage
        $baggage = [
            [
                'Booking_ID' => 1,
                'Weight' => 23.5,
                'Baggage_Tag' => 'SKW001',
                'Baggage_Status' => 'Delivered',
            ],
            [
                'Booking_ID' => 1,
                'Weight' => 15.2,
                'Baggage_Tag' => 'SKW002',
                'Baggage_Status' => 'Delivered',
            ],
            [
                'Booking_ID' => 2,
                'Weight' => 28.0,
                'Baggage_Tag' => 'SKW003',
                'Baggage_Status' => 'In Transit',
            ],
            [
                'Booking_ID' => 3,
                'Weight' => 12.8,
                'Baggage_Tag' => 'SKW004',
                'Baggage_Status' => 'Delivered',
            ],
            [
                'Booking_ID' => 4,
                'Weight' => 32.1,
                'Baggage_Tag' => 'SKW005',
                'Baggage_Status' => 'Lost',
            ],
        ];

        foreach ($baggage as $baggageData) {
            Baggage::create($baggageData);
        }

        $this->command->info('Sample airports, flights, staff, loyalty programs, and baggage created successfully!');
    }
}
