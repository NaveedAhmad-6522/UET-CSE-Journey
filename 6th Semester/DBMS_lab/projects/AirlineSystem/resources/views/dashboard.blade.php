<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard - SkyWay Airlines</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    <style>
        .dashboard-header {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 60px 0;
        }
        .stat-card {
            transition: transform 0.3s ease;
        }
        .stat-card:hover {
            transform: translateY(-5px);
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
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown">
                            <i class="fas fa-user me-1"></i>{{ Auth::user()->name }}
                        </a>
                        <ul class="dropdown-menu">
                            <li><a class="dropdown-item active" href="{{ route('dashboard') }}">Dashboard</a></li>
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
                </ul>
            </div>
        </div>
    </nav>

    <!-- Dashboard Header -->
    <section class="dashboard-header">
        <div class="container">
            <div class="row align-items-center">
                <div class="col-lg-8">
                    <h1 class="display-5 fw-bold mb-3">Welcome back, {{ Auth::user()->name }}!</h1>
                    <p class="lead mb-0">Manage your bookings and travel plans</p>
                </div>
                <div class="col-lg-4 text-lg-end">
                    <a href="{{ route('search.flights') }}" class="btn btn-light btn-lg">
                        <i class="fas fa-search me-2"></i>Search Flights
                    </a>
                </div>
            </div>
        </div>
    </section>

    <!-- Dashboard Content -->
    <section class="py-5">
        <div class="container">
            @if(session('success'))
                <div class="alert alert-success alert-dismissible fade show" role="alert">
                    {{ session('success') }}
                    <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
                </div>
            @endif

            <!-- Quick Stats -->
            <div class="row mb-5">
                <div class="col-md-4 mb-3">
                    <div class="card stat-card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-calendar-check fa-3x text-primary mb-3"></i>
                            <h4 class="card-title">{{ $bookings->count() }}</h4>
                            <p class="card-text text-muted">Total Bookings</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-4 mb-3">
                    <div class="card stat-card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-plane fa-3x text-success mb-3"></i>
                            <h4 class="card-title">{{ $bookings->where('Status', 'confirmed')->count() }}</h4>
                            <p class="card-text text-muted">Confirmed Flights</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-4 mb-3">
                    <div class="card stat-card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-suitcase fa-3x text-warning mb-3"></i>
                            <h4 class="card-title">{{ $bookings->sum(function($booking) { return $booking->baggage->count(); }) }}</h4>
                            <p class="card-text text-muted">Baggage Items</p>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Recent Bookings -->
            <div class="row">
                <div class="col-12">
                    <div class="card border-0 shadow-sm">
                        <div class="card-header bg-primary text-white">
                            <h4 class="mb-0"><i class="fas fa-history me-2"></i>Recent Bookings</h4>
                        </div>
                        <div class="card-body">
                            @if($bookings->count() > 0)
                                <div class="table-responsive">
                                    <table class="table table-hover">
                                        <thead>
                                            <tr>
                                                <th>Booking ID</th>
                                                <th>Flight</th>
                                                <th>Route</th>
                                                <th>Date</th>
                                                <th>Status</th>
                                                <th>Actions</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                            @foreach($bookings as $booking)
                                            <tr>
                                                <td>#{{ $booking->Booking_ID }}</td>
                                                <td>
                                                    <strong>{{ $booking->flight->flight_number ?? 'N/A' }}</strong>
                                                </td>
                                                <td>
                                                    {{ $booking->flight->departureAirport->Code ?? 'N/A' }} → 
                                                    {{ $booking->flight->arrivalAirport->Code ?? 'N/A' }}
                                                </td>
                                                <td>{{ $booking->Booking_Date ?? ($booking->created_at ? $booking->created_at->format('M d, Y') : 'N/A') }}</td>
                                                <td>
                                                    @if($booking->Status == 'confirmed')
                                                        <span class="badge bg-success">Confirmed</span>
                                                    @elseif($booking->Status == 'pending')
                                                        <span class="badge bg-warning">Pending</span>
                                                    @else
                                                        <span class="badge bg-secondary">{{ $booking->Status }}</span>
                                                    @endif
                                                </td>
                                                <td>
                                                    <a href="{{ route('flight.details', $booking->flight->Flight_ID ?? 1) }}" 
                                                       class="btn btn-sm btn-outline-primary">
                                                        <i class="fas fa-eye me-1"></i>View
                                                    </a>
                                                </td>
                                            </tr>
                                            @endforeach
                                        </tbody>
                                    </table>
                                </div>
                            @else
                                <div class="text-center py-5">
                                    <i class="fas fa-calendar-times fa-3x text-muted mb-3"></i>
                                    <h5>No bookings yet</h5>
                                    <p class="text-muted">Start your journey by booking your first flight!</p>
                                    <a href="{{ route('search.flights') }}" class="btn btn-primary">
                                        <i class="fas fa-search me-2"></i>Search Flights
                                    </a>
                                </div>
                            @endif
                        </div>
                    </div>
                </div>
            </div>

            <!-- Quick Actions -->
            <div class="row mt-5">
                <div class="col-12">
                    <h4 class="mb-4">Quick Actions</h4>
                </div>
                <div class="col-md-3 mb-3">
                    <div class="card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-search fa-2x text-primary mb-3"></i>
                            <h6>Search Flights</h6>
                            <p class="small text-muted">Find and book new flights</p>
                            <a href="{{ route('search.flights') }}" class="btn btn-outline-primary btn-sm">Search</a>
                        </div>
                    </div>
                </div>
                <div class="col-md-3 mb-3">
                    <div class="card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-user-edit fa-2x text-success mb-3"></i>
                            <h6>Update Profile</h6>
                            <p class="small text-muted">Manage your account details</p>
                            <a href="{{ route('profile.edit') }}" class="btn btn-outline-success btn-sm">Edit</a>
                        </div>
                    </div>
                </div>
                <div class="col-md-3 mb-3">
                    <div class="card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-suitcase fa-2x text-warning mb-3"></i>
                            <h6>Baggage</h6>
                            <p class="small text-muted">Track your baggage</p>
                            <a href="{{ route('user.baggage.index') }}" class="btn btn-outline-warning btn-sm">Track</a>
                        </div>
                    </div>
                </div>
                <div class="col-md-3 mb-3">
                    <div class="card border-0 shadow-sm h-100">
                        <div class="card-body text-center">
                            <i class="fas fa-headset fa-2x text-info mb-3"></i>
                            <h6>Support</h6>
                            <p class="small text-muted">Get help and contact us</p>
                            <a href="{{ route('contact') }}" class="btn btn-outline-info btn-sm">Contact</a>
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
</body>
</html>
