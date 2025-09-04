
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreateStaffTable extends Migration
{
    public function up()
    {
        Schema::create('staff', function (Blueprint $table) {
            $table->id('Staff_ID');
            $table->string('Name', 100);
            $table->string('Role', 50);
            $table->string('Contact_Number', 20);
            $table->unsignedBigInteger('Assigned_Flight_ID')->nullable();
            $table->foreign('Assigned_Flight_ID')->references('Flight_ID')->on('flights');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('staff');
    }
}