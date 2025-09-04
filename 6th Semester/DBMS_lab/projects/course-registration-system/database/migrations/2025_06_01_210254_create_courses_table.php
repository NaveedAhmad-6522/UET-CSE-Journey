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
        Schema::create('courses', function (Blueprint $table) {
            $table->id('course_id'); // Primary key
            $table->string('course_code')->unique(); // e.g., CS101
            $table->string('course_name');
            $table->unsignedInteger('credit_hours');
            $table->unsignedBigInteger('instructor_id');
            $table->unsignedBigInteger('department_id');
            $table->timestamps();

            // Foreign key constraints
            $table->foreign('instructor_id')
                  ->references('instructor_id')
                  ->on('instructors')
                  ->onDelete('cascade');

            $table->foreign('department_id')
                  ->references('department_id')
                  ->on('departments')
                  ->onDelete('cascade');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('courses');
    }
};