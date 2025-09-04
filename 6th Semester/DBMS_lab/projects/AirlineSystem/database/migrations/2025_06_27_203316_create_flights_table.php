
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreateFlightsTable extends Migration
{
    public function up()
    {
        Schema::create('flights', function (Blueprint $table) {
            $table->id('Flight_ID');
            $table->string('Airline_Name', 100);
            $table->unsignedBigInteger('Source');
            $table->unsignedBigInteger('Destination');
            $table->dateTime('Departure_Time');
            $table->dateTime('Arrival_Time');
            $table->foreign('Source')->references('Airport_ID')->on('airports');
            $table->foreign('Destination')->references('Airport_ID')->on('airports');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('flights');
    }
}