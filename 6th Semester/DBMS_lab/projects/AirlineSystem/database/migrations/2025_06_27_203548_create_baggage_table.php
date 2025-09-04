
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreateBaggageTable extends Migration
{
    public function up()
    {
        Schema::create('baggage', function (Blueprint $table) {
            $table->id('Baggage_ID');
            $table->unsignedBigInteger('Booking_ID');
            $table->decimal('Weight', 5, 2);
            $table->string('Baggage_Tag', 50);
            $table->string('Baggage_Status', 50);
            $table->foreign('Booking_ID')->references('Booking_ID')->on('bookings');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('baggage');
    }
}
