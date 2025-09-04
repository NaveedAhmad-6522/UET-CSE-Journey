<?php

use App\Http\Controllers\ProfileController;
use App\Http\Controllers\AuthController;
use App\Http\Controllers\HomeController;
use App\Http\Controllers\AdminController;
use Illuminate\Support\Facades\Route;
use Illuminate\Support\Facades\Mail;

// Public routes
Route::get('/', [HomeController::class, 'index'])->name('home');
Route::get('/about', [HomeController::class, 'about'])->name('about');
Route::get('/contact', [HomeController::class, 'contact'])->name('contact');
Route::get('/search-flights', [HomeController::class, 'searchFlights'])->name('search.flights');
Route::get('/flight/{id}', [HomeController::class, 'flightDetails'])->name('flight.details');

// Authentication routes
Route::get('/login', [AuthController::class, 'showLogin'])->name('login');
Route::post('/login', [AuthController::class, 'login']);
Route::get('/register', [AuthController::class, 'showRegister'])->name('register');
Route::post('/register', [AuthController::class, 'register']);
Route::post('/logout', [AuthController::class, 'logout'])->name('logout');

// Admin login
Route::get('/admin/login', [AuthController::class, 'showAdminLogin'])->name('admin.login');
Route::post('/admin/login', [AuthController::class, 'adminLogin']);

// User dashboard (authenticated) - Only for non-admin users
Route::middleware(['auth', 'user'])->group(function () {
    Route::get('/dashboard', [HomeController::class, 'dashboard'])->name('dashboard');
    Route::get('/profile', [ProfileController::class, 'edit'])->name('profile.edit');
    Route::patch('/profile', [ProfileController::class, 'update'])->name('profile.update');
    Route::delete('/profile', [ProfileController::class, 'destroy'])->name('profile.destroy');
});

// Admin routes - Only for admin users
Route::middleware(['auth', 'admin'])->prefix('admin')->name('admin.')->group(function () {
    Route::get('/dashboard', [AdminController::class, 'dashboard'])->name('dashboard');
    Route::get('/profile', [AdminController::class, 'profile'])->name('profile');
    Route::patch('/profile', [AdminController::class, 'updateProfile'])->name('profile.update');
});

// Resource routes for admin management - Only for admin users
Route::middleware(['auth', 'admin'])->prefix('admin')->name('admin.')->group(function () {
    Route::resource('passengers', \App\Http\Controllers\PassengerController::class);
    Route::resource('flights', \App\Http\Controllers\FlightController::class);
    Route::resource('bookings', \App\Http\Controllers\BookingController::class);
    Route::patch('bookings/{id}/confirm', [\App\Http\Controllers\BookingController::class, 'confirmBooking'])->name('bookings.confirm');
    Route::resource('payments', \App\Http\Controllers\PaymentController::class);
    Route::resource('airports', \App\Http\Controllers\AirportController::class);
    Route::resource('seats', \App\Http\Controllers\SeatController::class);
    Route::resource('staff', \App\Http\Controllers\StaffController::class);
    Route::resource('loyalty_programs', \App\Http\Controllers\LoyaltyProgramController::class);
    Route::resource('baggage', \App\Http\Controllers\BaggageController::class);
});

// User resource routes (for passengers to manage their bookings) - Only for non-admin users
Route::middleware(['auth', 'user'])->prefix('user')->name('user.')->group(function () {
    Route::resource('bookings', \App\Http\Controllers\BookingController::class);
    Route::resource('baggage', \App\Http\Controllers\BaggageController::class);
});

// Temporary test route for debugging
Route::get('/test-admin', function() {
    try {
        $stats = [
            'total_flights' => App\Models\Flight::count(),
            'total_bookings' => App\Models\Booking::count(),
            'total_passengers' => App\Models\Passenger::count(),
            'total_revenue' => App\Models\Payment::sum('Amount'),
            'upcoming_flights' => App\Models\Flight::where('Departure_Time', '>', now())->count(),
            'pending_payments' => App\Models\Payment::where('status', 'pending')->count(),
        ];

        $recent_bookings = App\Models\Booking::with(['passenger.user', 'flight'])
            ->latest()
            ->take(5)
            ->get();

        $upcoming_flights = App\Models\Flight::with(['departureAirport', 'arrivalAirport'])
            ->where('Departure_Time', '>', now())
            ->orderBy('Departure_Time')
            ->take(3)
            ->get();

        return response()->json([
            'stats' => $stats,
            'recent_bookings_count' => $recent_bookings->count(),
            'upcoming_flights_count' => $upcoming_flights->count(),
            'sample_booking' => $recent_bookings->first(),
            'sample_flight' => $upcoming_flights->first()
        ]);
    } catch (\Exception $e) {
        return response()->json([
            'error' => $e->getMessage(),
            'line' => $e->getLine(),
            'file' => $e->getFile()
        ]);
    }
});

// Test mail route
Route::get('/test-mail', function() {
    try {
        Mail::raw('Test email from SkyWay Airlines', function($message) {
            $message->to('rukhma207@gmail.com')->subject('Test Email');
        });
        return 'Email sent successfully!';
    } catch (\Exception $e) {
        return 'Email failed: ' . $e->getMessage();
    }
});

// Test baggage routes
Route::get('/test-baggage-routes', function() {
    try {
        $routes = [
            'admin.baggage.index' => route('admin.baggage.index'),
            'admin.baggage.create' => route('admin.baggage.create'),
            'admin.baggage.store' => route('admin.baggage.store'),
            'user.baggage.index' => route('user.baggage.index'),
            'user.baggage.create' => route('user.baggage.create'),
            'user.baggage.store' => route('user.baggage.store'),
        ];
        return response()->json($routes);
    } catch (\Exception $e) {
        return response()->json([
            'error' => $e->getMessage(),
            'line' => $e->getLine(),
            'file' => $e->getFile()
        ]);
    }
});

// Test role-based access
Route::get('/test-role-access', function() {
    if (!auth()->check()) {
        return response()->json(['message' => 'Not authenticated']);
    }
    
    $user = auth()->user();
    return response()->json([
        'user_id' => $user->id,
        'name' => $user->name,
        'role' => $user->role,
        'is_admin' => $user->isAdmin(),
        'is_passenger' => $user->isPassenger(),
        'is_staff' => $user->isStaff(),
        'user_dashboard_url' => route('dashboard'),
        'admin_dashboard_url' => route('admin.dashboard'),
    ]);
});

require __DIR__.'/auth.php';
