
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreateBookingsTable extends Migration
{
    public function up()
    {
        Schema::create('bookings', function (Blueprint $table) {
            $table->id('Booking_ID');
            $table->unsignedBigInteger('Passenger_ID');
            $table->unsignedBigInteger('Flight_ID');
            $table->date('Booking_Date');
            $table->string('Status', 50);
            $table->foreign('Passenger_ID')->references('Passenger_ID')->on('passengers');
            $table->foreign('Flight_ID')->references('Flight_ID')->on('flights');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('bookings');
    }
}