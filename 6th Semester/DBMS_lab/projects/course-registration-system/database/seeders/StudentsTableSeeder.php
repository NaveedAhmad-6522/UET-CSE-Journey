<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class StudentsTableSeeder extends Seeder
{
    public function run()
    {
        DB::table('students')->insert([
            [
                'first_name' => 'Ali',
                'last_name' => 'Khan',
                'email' => 'ali@example.com',
                'phone' => '03001234567',
                'department_id' => 1,
                'created_at' => now(),
                'updated_at' => now(),
            ],
            [
                'first_name' => 'Fatima',
                'last_name' => 'Noor',
                'email' => 'fatima@example.com',
                'phone' => '03007654321',
                'department_id' => 2,
                'created_at' => now(),
                'updated_at' => now(),
            ],
            [
                'first_name' => 'Ahmed',
                'last_name' => 'Raza',
                'email' => 'ahmed@example.com',
                'phone' => '03111234567',
                'department_id' => 3,
                'created_at' => now(),
                'updated_at' => now(),
            ],
        ]);
    }
}