<?php
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return response()->json(['status' => 'Laravel API is running']);
});