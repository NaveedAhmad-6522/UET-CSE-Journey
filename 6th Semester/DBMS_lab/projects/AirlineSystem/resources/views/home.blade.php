<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SkyWay Airlines - Book Your Flight</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    <style>
        .hero-section {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 100px 0;
        }
        .flight-search-card {
            background: rgba(255, 255, 255, 0.95);
            border-radius: 15px;
            padding: 30px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.1);
        }
        .feature-card {
            transition: transform 0.3s ease;
        }
        .feature-card:hover {
            transform: translateY(-5px);
        }
        .navbar-brand {
            font-weight: bold;
            font-size: 1.5rem;
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

    <!-- Hero Section -->
    <section class="hero-section">
        <div class="container">
            <div class="row align-items-center">
                <div class="col-lg-6">
                    <h1 class="display-4 fw-bold mb-4">Fly with Confidence</h1>
                    <p class="lead mb-4">Discover amazing destinations with SkyWay Airlines. Book your next adventure with ease and comfort.</p>
                    <a href="{{ route('search.flights') }}" class="btn btn-light btn-lg">
                        <i class="fas fa-search me-2"></i>Search Flights
                    </a>
                </div>
                <div class="col-lg-6">
                    <div class="flight-search-card">
                        <h4 class="text-dark mb-4">Find Your Perfect Flight</h4>
                        <form action="{{ route('search.flights') }}" method="GET">
                            <div class="row g-3">
                                <div class="col-md-6">
                                    <label class="form-label text-dark">From</label>
                                    <select name="from" class="form-select" required>
                                        <option value="">Select departure</option>
                                        @foreach($airports as $airport)
                                            <option value="{{ $airport->Airport_ID }}">{{ $airport->Name }} ({{ $airport->Code }})</option>
                                        @endforeach
                                    </select>
                                </div>
                                <div class="col-md-6">
                                    <label class="form-label text-dark">To</label>
                                    <select name="to" class="form-select" required>
                                        <option value="">Select destination</option>
                                        @foreach($airports as $airport)
                                            <option value="{{ $airport->Airport_ID }}">{{ $airport->Name }} ({{ $airport->Code }})</option>
                                        @endforeach
                                    </select>
                                </div>
                                <div class="col-12">
                                    <label class="form-label text-dark">Date</label>
                                    <input type="date" name="date" class="form-control" required min="{{ date('Y-m-d') }}">
                                </div>
                                <div class="col-12">
                                    <button type="submit" class="btn btn-primary w-100">
                                        <i class="fas fa-search me-2"></i>Search Flights
                                    </button>
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Features Section -->
    <section class="py-5">
        <div class="container">
            <div class="row text-center mb-5">
                <div class="col-12">
                    <h2 class="display-5 fw-bold">Why Choose SkyWay Airlines?</h2>
                    <p class="lead text-muted">Experience the best in air travel with our premium services</p>
                </div>
            </div>
            <div class="row g-4">
                <div class="col-md-4">
                    <div class="card feature-card h-100 border-0 shadow-sm">
                        <div class="card-body text-center p-4">
                            <i class="fas fa-shield-alt fa-3x text-primary mb-3"></i>
                            <h5 class="card-title">Safe & Secure</h5>
                            <p class="card-text">Your safety is our top priority with state-of-the-art aircraft and experienced pilots.</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="card feature-card h-100 border-0 shadow-sm">
                        <div class="card-body text-center p-4">
                            <i class="fas fa-clock fa-3x text-success mb-3"></i>
                            <h5 class="card-title">On-Time Flights</h5>
                            <p class="card-text">We pride ourselves on punctuality with one of the best on-time performance records.</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="card feature-card h-100 border-0 shadow-sm">
                        <div class="card-body text-center p-4">
                            <i class="fas fa-star fa-3x text-warning mb-3"></i>
                            <h5 class="card-title">Premium Service</h5>
                            <p class="card-text">Enjoy exceptional service with our dedicated staff and comfortable seating.</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Upcoming Flights Section -->
    @if($flights->count() > 0)
    <section class="py-5 bg-light">
        <div class="container">
            <div class="row mb-4">
                <div class="col-12">
                    <h2 class="display-6 fw-bold">Upcoming Flights</h2>
                    <p class="text-muted">Check out our latest flight schedules</p>
                </div>
            </div>
            <div class="row g-4">
                @foreach($flights as $flight)
                <div class="col-md-6 col-lg-4">
                    <div class="card h-100 border-0 shadow-sm">
                        <div class="card-body">
                            <div class="d-flex justify-content-between align-items-center mb-3">
                                <h6 class="card-title mb-0">{{ $flight->departureAirport->Code ?? 'N/A' }} → {{ $flight->arrivalAirport->Code ?? 'N/A' }}</h6>
                                <span class="badge bg-primary">{{ $flight->Airline_Name }}</span>
                            </div>
                            <p class="card-text">
                                <small class="text-muted">
                                    <i class="fas fa-calendar me-1"></i>
                                    {{ $flight->Departure_Time ? $flight->Departure_Time->format('M d, Y') : 'N/A' }}
                                </small>
                            </p>
                            <p class="card-text">
                                <small class="text-muted">
                                    <i class="fas fa-clock me-1"></i>
                                    {{ $flight->Departure_Time ? $flight->Departure_Time->format('H:i') : 'N/A' }} - {{ $flight->Arrival_Time ? $flight->Arrival_Time->format('H:i') : 'N/A' }}
                                </small>
                            </p>
                            <a href="{{ route('flight.details', $flight->Flight_ID) }}" class="btn btn-outline-primary btn-sm">
                                View Details
                            </a>
                        </div>
                    </div>
                </div>
                @endforeach
            </div>
        </div>
    </section>
    @endif

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
</body>
</html> 
