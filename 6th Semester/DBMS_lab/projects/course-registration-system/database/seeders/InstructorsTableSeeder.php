<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class InstructorsTableSeeder extends Seeder
{
    public function run()
    {
        DB::table('instructors')->insert([
            [
                'first_name' => 'John',
                'last_name' => 'Doe',
                'email' => 'john.doe@example.com',
                'phone' => '03001234567',
                'department_id' => 1,
            ],
            [
                'first_name' => 'Jane',
                'last_name' => 'Smith',
                'email' => 'jane.smith@example.com',
                'phone' => '03007654321',
                'department_id' => 2,
            ],
            // Add more instructors here
        ]);
    }
}