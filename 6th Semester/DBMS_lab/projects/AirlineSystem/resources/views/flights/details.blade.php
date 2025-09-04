<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Flight Details - SkyWay Airlines</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    <style>
        .flight-header {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 60px 0;
        }
        .detail-card {
            transition: transform 0.3s ease;
        }
        .detail-card:hover {
            transform: translateY(-2px);
        }
    </style>
</head>
<body>
    <!-- Navigation -->
    <nav class="navbar navbar-expand-lg navbar-dark bg-primary">
        <div class="container">
            <a class="navbar-brand" href="/">
                <i class="fas fa-plane me-2"></i>
                SkyWay Airlines
            </a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNav">
                <ul class="navbar-nav me-auto">
                    <li class="nav-item">
                        <a class="nav-link" href="/">Home</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="{{ route('search.flights') }}">Flights</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="{{ route('about') }}">About</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="{{ route('contact') }}">Contact</a>
                    </li>
                </ul>
                <ul class="navbar-nav">
                    @auth
                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown">
                                <i class="fas fa-user me-1"></i>{{ Auth::user()->name }}
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="{{ route('dashboard') }}">Dashboard</a></li>
                                <li><a class="dropdown-item" href="{{ route('profile.edit') }}">Profile</a></li>
                                <li><hr class="dropdown-divider"></li>
                                <li>
                                    <form method="POST" action="{{ route('logout') }}">
                                        @csrf
                                        <button type="submit" class="dropdown-item">Logout</button>
                                    </form>
                                </li>
                            </ul>
                        </li>
                    @else
                        <li class="nav-item">
                            <a class="nav-link" href="{{ route('login') }}">Login</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="{{ route('register') }}">Register</a>
                        </li>
                    @endauth
                </ul>
            </div>
        </div>
    </nav>

    <!-- Flight Header -->
    <section class="flight-header">
        <div class="container">
            <div class="row align-items-center">
                <div class="col-lg-8">
                    <h1 class="display-5 fw-bold mb-3">{{ $flight->Airline_Name }}</h1>
                    <p class="lead mb-0">
                        {{ $flight->departureAirport->Name ?? 'N/A' }} ({{ $flight->departureAirport->Code ?? 'N/A' }}) 
                        <i class="fas fa-arrow-right mx-3"></i>
                        {{ $flight->arrivalAirport->Name ?? 'N/A' }} ({{ $flight->arrivalAirport->Code ?? 'N/A' }})
                    </p>
                </div>
                <div class="col-lg-4 text-lg-end">
                    <h3 class="mb-0">${{ number_format($flight->price ?? 299, 2) }}</h3>
                    <p class="mb-0">per passenger</p>
                </div>
            </div>
        </div>
    </section>

    <!-- Flight Details -->
    <section class="py-5">
        <div class="container">
            <div class="row">
                <!-- Main Flight Info -->
                <div class="col-lg-8">
                    <div class="card border-0 shadow-sm mb-4">
                        <div class="card-header bg-primary text-white">
                            <h4 class="mb-0"><i class="fas fa-info-circle me-2"></i>Flight Information</h4>
                        </div>
                        <div class="card-body">
                            <div class="row">
                                <div class="col-md-6">
                                    <h6 class="text-muted">Departure</h6>
                                    <p class="fw-bold">{{ $flight->Departure_Time ? $flight->Departure_Time->format('H:i') : 'N/A' }}</p>
                                    <p class="text-muted">{{ $flight->Departure_Time ? $flight->Departure_Time->format('l, F d, Y') : 'N/A' }}</p>
                                    <p class="mb-0">{{ $flight->departureAirport->Name }}</p>
                                </div>
                                <div class="col-md-6">
                                    <h6 class="text-muted">Arrival</h6>
                                    <p class="fw-bold">{{ $flight->Arrival_Time ? $flight->Arrival_Time->format('H:i') : 'N/A' }}</p>
                                    <p class="text-muted">{{ $flight->Arrival_Time ? $flight->Arrival_Time->format('l, F d, Y') : 'N/A' }}</p>
                                    <p class="mb-0">{{ $flight->arrivalAirport->Name }}</p>
                                </div>
                            </div>
                            <hr>
                            <div class="row">
                                <div class="col-md-4">
                                    <h6 class="text-muted">Duration</h6>
                                    <p class="fw-bold">{{ $flight->duration ?? 'N/A' }}</p>
                                </div>
                                <div class="col-md-4">
                                    <h6 class="text-muted">Aircraft</h6>
                                    <p class="fw-bold">{{ $flight->aircraft_type ?? 'Boeing 737' }}</p>
                                </div>
                                <div class="col-md-4">
                                    <h6 class="text-muted">Status</h6>
                                    <span class="badge bg-success">On Time</span>
                                </div>
                            </div>
                        </div>
                    </div>

                    <!-- Seat Information -->
                    <div class="card border-0 shadow-sm mb-4">
                        <div class="card-header bg-info text-white">
                            <h4 class="mb-0"><i class="fas fa-chair me-2"></i>Seat Information</h4>
                        </div>
                        <div class="card-body">
                            <div class="row">
                                <div class="col-md-3">
                                    <div class="text-center">
                                        <i class="fas fa-chair fa-2x text-success mb-2"></i>
                                        <h6>Available</h6>
                                        <p class="fw-bold">{{ $flight->seats->where('status', 'available')->count() }}</p>
                                    </div>
                                </div>
                                <div class="col-md-3">
                                    <div class="text-center">
                                        <i class="fas fa-chair fa-2x text-danger mb-2"></i>
                                        <h6>Booked</h6>
                                        <p class="fw-bold">{{ $flight->seats->where('status', 'booked')->count() }}</p>
                                    </div>
                                </div>
                                <div class="col-md-3">
                                    <div class="text-center">
                                        <i class="fas fa-crown fa-2x text-warning mb-2"></i>
                                        <h6>Premium</h6>
                                        <p class="fw-bold">{{ $flight->seats->where('class', 'premium')->count() }}</p>
                                    </div>
                                </div>
                                <div class="col-md-3">
                                    <div class="text-center">
                                        <i class="fas fa-economy fa-2x text-primary mb-2"></i>
                                        <h6>Economy</h6>
                                        <p class="fw-bold">{{ $flight->seats->where('class', 'economy')->count() }}</p>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

                <!-- Booking Sidebar -->
                <div class="col-lg-4">
                    <div class="card border-0 shadow-sm sticky-top" style="top: 20px;">
                        <div class="card-header bg-primary text-white">
                            <h4 class="mb-0"><i class="fas fa-ticket-alt me-2"></i>Book This Flight</h4>
                        </div>
                        <div class="card-body">
                            <div class="mb-3">
                                <label class="form-label">Number of Passengers</label>
                                <select class="form-select" id="passengerCount">
                                    @for($i = 1; $i <= 9; $i++)
                                        <option value="{{ $i }}">{{ $i }} {{ $i == 1 ? 'Passenger' : 'Passengers' }}</option>
                                    @endfor
                                </select>
                            </div>
                            
                            <div class="mb-3">
                                <label class="form-label">Seat Class</label>
                                <select class="form-select" id="seatClass">
                                    <option value="economy">Economy Class</option>
                                    <option value="premium">Premium Economy</option>
                                    <option value="business">Business Class</option>
                                </select>
                            </div>

                            <div class="mb-3">
                                <div class="d-flex justify-content-between">
                                    <span>Price per passenger:</span>
                                    <span class="fw-bold">${{ number_format($flight->price ?? 299, 2) }}</span>
                                </div>
                                <div class="d-flex justify-content-between">
                                    <span>Taxes & Fees:</span>
                                    <span>$25.00</span>
                                </div>
                                <hr>
                                <div class="d-flex justify-content-between">
                                    <span class="fw-bold">Total:</span>
                                    <span class="fw-bold text-primary" id="totalPrice">${{ number_format(($flight->price ?? 299) + 25, 2) }}</span>
                                </div>
                            </div>

                            @auth
                                <a href="{{ route('user.bookings.create', ['flight_id' => $flight->Flight_ID]) }}" class="btn btn-primary btn-lg w-100 mb-2">
                                    <i class="fas fa-credit-card me-2"></i>Book Now
                                </a>
                            @else
                                <a href="{{ route('login') }}" class="btn btn-primary btn-lg w-100 mb-2">
                                    <i class="fas fa-sign-in-alt me-2"></i>Login to Book
                                </a>
                            @endauth
                            
                            <a href="{{ route('search.flights') }}" class="btn btn-outline-secondary w-100">
                                <i class="fas fa-search me-2"></i>Search Other Flights
                            </a>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Footer -->
    <footer class="bg-dark text-white py-4">
        <div class="container">
            <div class="row">
                <div class="col-md-6">
                    <h5><i class="fas fa-plane me-2"></i>SkyWay Airlines</h5>
                    <p class="mb-0">Your trusted partner in air travel.</p>
                </div>
                <div class="col-md-6 text-md-end">
                    <p class="mb-0">&copy; 2024 SkyWay Airlines. All rights reserved.</p>
                </div>
            </div>
        </div>
    </footer>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
    <script>
        // Update total price when passenger count changes
        document.getElementById('passengerCount').addEventListener('change', function() {
            const passengerCount = parseInt(this.value);
            const basePrice = {{ $flight->price ?? 299 }};
            const taxes = 25;
            const total = (basePrice + taxes) * passengerCount;
            document.getElementById('totalPrice').textContent = '$' + total.toFixed(2);
        });
    </script>
</body>
</html> 
