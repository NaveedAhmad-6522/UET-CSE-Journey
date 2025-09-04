
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreateSeatsTable extends Migration
{
    public function up()
    {
        Schema::create('seats', function (Blueprint $table) {
            $table->id('Seat_ID');
            $table->unsignedBigInteger('Flight_ID');
            $table->string('Seat_Number', 10);
            $table->string('Class', 50);
            $table->string('Availability_Status', 20);
            $table->foreign('Flight_ID')->references('Flight_ID')->on('flights');
            $table->unique(['Flight_ID', 'Seat_Number']);
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('seats');
    }
}