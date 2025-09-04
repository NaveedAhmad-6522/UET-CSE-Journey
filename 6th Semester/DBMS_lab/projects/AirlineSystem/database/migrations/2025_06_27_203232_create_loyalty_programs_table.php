<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateLoyaltyProgramsTable extends Migration
{
    public function up()
    {
        Schema::create('loyalty_programs', function (Blueprint $table) {
            $table->id('Loyalty_ID');
            $table->string('Program_Name', 100);
            $table->integer('Miles_Earned');
            $table->string('Membership_Level', 50);
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('loyalty_programs');
    }
}
