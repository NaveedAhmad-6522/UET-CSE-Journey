
<?php
use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
class CreateAirportsTable extends Migration
{
    public function up()
    {
        Schema::create('airports', function (Blueprint $table) {
            $table->id('Airport_ID');
            $table->string('Name', 100);
            $table->string('City', 100);
            $table->string('Country', 100);
            $table->string('Code', 10);
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('airports');
    }
}
