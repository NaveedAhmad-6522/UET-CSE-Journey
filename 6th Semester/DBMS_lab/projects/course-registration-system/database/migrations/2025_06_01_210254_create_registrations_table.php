<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
use Illuminate\Support\Facades\DB; // ✅ correct

return new class extends Migration {
    public function up(): void
    {
        Schema::create('registrations', function (Blueprint $table) {
            $table->id('registration_id');
            $table->unsignedBigInteger('student_id');
            $table->unsignedBigInteger('course_id');
            $table->date('registration_date');
            $table->timestamps();
        });

        // OPTIONAL: Use DB here if you need to insert default rows
        // DB::table('registrations')->insert([...]);
    }

    public function down(): void
    {
        Schema::dropIfExists('registrations');
    }
};