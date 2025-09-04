
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreatePaymentsTable extends Migration
{
    public function up()
    {
        Schema::create('payments', function (Blueprint $table) {
            $table->id('Payment_ID');
            $table->unsignedBigInteger('Booking_ID')->unique();
            $table->decimal('Amount', 10, 2);
            $table->date('Payment_Date');
            $table->string('Payment_Method', 50);
            $table->foreign('Booking_ID')->references('Booking_ID')->on('bookings');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('payments');
    }
}