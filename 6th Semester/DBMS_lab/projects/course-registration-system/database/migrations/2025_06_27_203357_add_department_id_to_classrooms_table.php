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
    Schema::table('classrooms', function (Blueprint $table) {
        $table->unsignedBigInteger('department_id')->nullable()->after('building_name');

        $table->foreign('department_id')
              ->references('department_id')
              ->on('departments')
              ->onDelete('set null');
    });
}

public function down(): void
{
    Schema::table('classrooms', function (Blueprint $table) {
        $table->dropForeign(['department_id']);
        $table->dropColumn('department_id');
    });
}
};
