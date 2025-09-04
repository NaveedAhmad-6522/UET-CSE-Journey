
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreatePassengersTable extends Migration
{
    public function up()
    {
        Schema::create('passengers', function (Blueprint $table) {
            $table->id('Passenger_ID');
            $table->string('Name', 100);
            $table->string('Email', 100);
            $table->string('Phone', 20);
            $table->string('Passport_No', 50);
            $table->unsignedBigInteger('Loyalty_ID')->nullable();
            $table->foreign('Loyalty_ID')->references('Loyalty_ID')->on('loyalty_programs')->onDelete('set null');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('passengers');
    }
}