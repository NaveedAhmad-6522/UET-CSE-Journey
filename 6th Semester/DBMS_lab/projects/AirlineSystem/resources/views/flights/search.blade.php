<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Flights - SkyWay Airlines</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    <style>
        .search-section {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 60px 0;
        }
        .flight-card {
            transition: transform 0.3s ease, box-shadow 0.3s ease;
        }
        .flight-card:hover {
            transform: translateY(-5px);
            box-shadow: 0 10px 25px rgba(0,0,0,0.1);
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
                        <a class="nav-link active" href="{{ route('search.flights') }}">Flights</a>
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

    <!-- Search Section -->
    <section class="search-section">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-lg-8">
                    <div class="text-center mb-4">
                        <h1 class="display-5 fw-bold mb-3">Find Your Perfect Flight</h1>
                        <p class="lead">Search for flights to your desired destination</p>
                    </div>
                    
                    <div class="card border-0 shadow">
                        <div class="card-body p-4">
                            <form method="GET" action="{{ route('search.flights') }}">
                                <div class="row g-3">
                                    <div class="col-md-6">
                                        <label class="form-label">From</label>
                                        <select name="from" class="form-select" required>
                                            <option value="">Select departure airport</option>
                                            @foreach($airports as $airport)
                                                <option value="{{ $airport->Airport_ID }}" {{ request('from') == $airport->Airport_ID ? 'selected' : '' }}>
                                                    {{ $airport->Name }} ({{ $airport->Code }})
                                                </option>
                                            @endforeach
                                        </select>
                                    </div>
                                    <div class="col-md-6">
                                        <label class="form-label">To</label>
                                        <select name="to" class="form-select" required>
                                            <option value="">Select destination airport</option>
                                            @foreach($airports as $airport)
                                                <option value="{{ $airport->Airport_ID }}" {{ request('to') == $airport->Airport_ID ? 'selected' : '' }}>
                                                    {{ $airport->Name }} ({{ $airport->Code }})
                                                </option>
                                            @endforeach
                                        </select>
                                    </div>
                                    <div class="col-md-6">
                                        <label class="form-label">Date</label>
                                        <input type="date" name="date" class="form-control" required 
                                               value="{{ request('date') }}" min="{{ date('Y-m-d') }}">
                                    </div>
                                    <div class="col-md-6">
                                        <label class="form-label">Passengers</label>
                                        <select name="passengers" class="form-select">
                                            @for($i = 1; $i <= 9; $i++)
                                                <option value="{{ $i }}" {{ request('passengers', 1) == $i ? 'selected' : '' }}>
                                                    {{ $i }} {{ $i == 1 ? 'Passenger' : 'Passengers' }}
                                                </option>
                                            @endfor
                                        </select>
                                    </div>
                                    <div class="col-12">
                                        <button type="submit" class="btn btn-primary btn-lg w-100">
                                            <i class="fas fa-search me-2"></i>Search Flights
                                        </button>
                                    </div>
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Results Section -->
    @if(request()->filled(['from', 'to', 'date']))
    <section class="py-5">
        <div class="container">
            <div class="row mb-4">
                <div class="col-12">
                    <h2 class="fw-bold">Search Results</h2>
                    <p class="text-muted">
                        @if($flights->count() > 0)
                            Found {{ $flights->count() }} flight(s) for your search
                        @else
                            No flights found for your search criteria
                        @endif
                    </p>
                </div>
            </div>

            @if($flights->count() > 0)
                <div class="row g-4">
                    @foreach($flights as $flight)
                    <div class="col-lg-6">
                        <div class="card flight-card h-100 border-0 shadow-sm">
                            <div class="card-body p-4">
                                <div class="d-flex justify-content-between align-items-start mb-3">
                                    <div>
                                        <h5 class="card-title mb-1">{{ $flight->Airline_Name }}</h5>
                                        <p class="text-muted mb-0">
                                            {{ $flight->departureAirport->Code ?? 'N/A' }} → {{ $flight->arrivalAirport->Code ?? 'N/A' }}
                                        </p>
                                    </div>
                                    <span class="badge bg-success">Available</span>
                                </div>
                                
                                <div class="row mb-3">
                                    <div class="col-6">
                                        <small class="text-muted">Departure</small>
                                        <p class="mb-0 fw-bold">{{ $flight->Departure_Time ? $flight->Departure_Time->format('H:i') : 'N/A' }}</p>
                                        <small class="text-muted">{{ $flight->Departure_Time ? $flight->Departure_Time->format('M d, Y') : 'N/A' }}</small>
                                    </div>
                                    <div class="col-6">
                                        <small class="text-muted">Arrival</small>
                                        <p class="mb-0 fw-bold">{{ $flight->Arrival_Time ? $flight->Arrival_Time->format('H:i') : 'N/A' }}</p>
                                        <small class="text-muted">{{ $flight->Arrival_Time ? $flight->Arrival_Time->format('M d, Y') : 'N/A' }}</small>
                                    </div>
                                </div>
                                
                                <div class="row mb-3">
                                    <div class="col-6">
                                        <small class="text-muted">Duration</small>
                                        <p class="mb-0">{{ $flight->duration ?? 'N/A' }}</p>
                                    </div>
                                    <div class="col-6">
                                        <small class="text-muted">Price</small>
                                        <p class="mb-0 fw-bold text-primary">${{ number_format($flight->price ?? 299, 2) }}</p>
                                    </div>
                                </div>
                                
                                <div class="d-grid gap-2">
                                    <a href="{{ route('flight.details', $flight->Flight_ID) }}" class="btn btn-outline-primary">
                                        <i class="fas fa-info-circle me-2"></i>View Details
                                    </a>
                                    @auth
                                        <a href="{{ route('user.bookings.create', ['flight_id' => $flight->Flight_ID]) }}" class="btn btn-primary">
                                            <i class="fas fa-ticket-alt me-2"></i>Book Now
                                        </a>
                                    @else
                                        <a href="{{ route('login') }}" class="btn btn-primary">
                                            <i class="fas fa-sign-in-alt me-2"></i>Login to Book
                                        </a>
                                    @endauth
                                </div>
                            </div>
                        </div>
                    </div>
                    @endforeach
                </div>
            @else
                <div class="text-center py-5">
                    <i class="fas fa-search fa-3x text-muted mb-3"></i>
                    <h4>No flights found</h4>
                    <p class="text-muted">Try adjusting your search criteria or check back later for new flights.</p>
                    <a href="{{ route('search.flights') }}" class="btn btn-primary">
                        <i class="fas fa-redo me-2"></i>New Search
                    </a>
                </div>
            @endif
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
