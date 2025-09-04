<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('schedules', function (Blueprint $table) {
            $table->id('schedule_id'); // Primary key
            $table->unsignedBigInteger('course_id');
            $table->unsignedBigInteger('classroom_id');
            $table->string('day_of_week'); // e.g., Monday, Tuesday
            $table->time('start_time');    // e.g., 09:00:00
            $table->time('end_time');      // e.g., 10:30:00
            $table->timestamps();

            // Foreign key constraints
            $table->foreign('course_id')
                  ->references('course_id')
                  ->on('courses')
                  ->onDelete('cascade');

            $table->foreign('classroom_id')
                  ->references('classroom_id')
                  ->on('classrooms')
                  ->onDelete('cascade');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('schedules');
    }
};