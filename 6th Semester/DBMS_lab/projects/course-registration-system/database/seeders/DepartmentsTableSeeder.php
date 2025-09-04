<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class DepartmentsTableSeeder extends Seeder
{
    public function run()
    {
        DB::table('departments')->insert([
            ['department_name' => 'Computer Science'],
            ['department_name' => 'Mathematics'],
            ['department_name' => 'Physics'],
            ['department_name' => 'Chemistry'],
        ]);
    }
}