<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Bookings - SkyWay Airlines</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
</head>
<body class="bg-light">
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

    <div class="container mt-4">
        <div class="row">
            <div class="col-12">
                <div class="card border-0 shadow-sm">
                    <div class="card-header bg-primary text-white">
                        <div class="d-flex justify-content-between align-items-center">
                            <h4 class="mb-0"><i class="fas fa-ticket-alt me-2"></i>My Bookings</h4>
                            <a href="{{ route('search.flights') }}" class="btn btn-light btn-sm">
                                <i class="fas fa-plus me-1"></i>Book New Flight
                            </a>
                        </div>
                    </div>
                    <div class="card-body p-4">
                        @if (session('success'))
                            <div class="alert alert-success">
                                {{ session('success') }}
                            </div>
                        @endif

                        @if (session('error'))
                            <div class="alert alert-danger">
                                {{ session('error') }}
                            </div>
                        @endif

                        @if($bookings->count() > 0)
                            <div class="table-responsive">
                                <table class="table table-hover">
                                    <thead class="table-light">
                                        <tr>
                                            <th>Booking ID</th>
                                            <th>Flight</th>
                                            <th>Route</th>
                                            <th>Date</th>
                                            <th>Passengers</th>
                                            <th>Class</th>
                                            <th>Status</th>
                                            <th>Actions</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        @foreach($bookings as $booking)
                                            <tr>
                                                <td>
                                                    <span class="badge bg-secondary">#{{ $booking->Booking_ID }}</span>
                                                </td>
                                                <td>
                                                    <strong>{{ $booking->flight->Airline_Name ?? 'N/A' }}</strong>
                                                </td>
                                                <td>
                                                    {{ $booking->flight->departureAirport->Code ?? 'N/A' }} → {{ $booking->flight->arrivalAirport->Code ?? 'N/A' }}
                                                </td>
                                                <td>
                                                    <div>
                                                        <strong>{{ $booking->flight && $booking->flight->Departure_Time ? $booking->flight->Departure_Time->format('M d, Y') : 'N/A' }}</strong>
                                                        <br>
                                                        <small class="text-muted">{{ $booking->flight && $booking->flight->Departure_Time ? $booking->flight->Departure_Time->format('H:i') : 'N/A' }}</small>
                                                    </div>
                                                </td>
                                                <td>
                                                    <span class="badge bg-info">{{ $booking->passenger_count ?? 1 }}</span>
                                                </td>
                                                <td>
                                                    <span class="badge bg-warning">{{ ucfirst($booking->seat_class ?? 'economy') }}</span>
                                                </td>
                                                <td>
                                                    @if($booking->Status === 'confirmed')
                                                        <span class="badge bg-success">Confirmed</span>
                                                    @elseif($booking->Status === 'pending')
                                                        <span class="badge bg-warning">Pending</span>
                                                    @else
                                                        <span class="badge bg-danger">Cancelled</span>
                                                    @endif
                                                </td>
                                                <td>
                                                    <div class="btn-group" role="group">
                                                        <a href="{{ route('flight.details', $booking->flight->Flight_ID ?? 1) }}" 
                                                           class="btn btn-sm btn-outline-primary">
                                                            <i class="fas fa-eye me-1"></i>View
                                                        </a>
                                                        
                                                        @if(auth()->user()->isAdmin())
                                                            <!-- Admin Actions -->
                                                            <a href="{{ route('admin.bookings.edit', $booking->Booking_ID) }}" 
                                                               class="btn btn-sm btn-outline-warning">
                                                                <i class="fas fa-edit me-1"></i>Edit
                                                            </a>
                                                            
                                                            @if($booking->Status === 'pending')
                                                                <form method="POST" action="{{ route('admin.bookings.confirm', $booking->Booking_ID) }}" 
                                                                      class="d-inline">
                                                                    @csrf
                                                                    @method('PATCH')
                                                                    <button type="submit" class="btn btn-sm btn-outline-success">
                                                                        <i class="fas fa-check me-1"></i>Confirm
                                                                    </button>
                                                                </form>
                                                            @endif
                                                            
                                                            <form method="POST" action="{{ route('admin.bookings.destroy', $booking->Booking_ID) }}" 
                                                                  class="d-inline" onsubmit="return confirm('Are you sure you want to delete this booking?')">
                                                                @csrf
                                                                @method('DELETE')
                                                                <button type="submit" class="btn btn-sm btn-outline-danger">
                                                                    <i class="fas fa-trash me-1"></i>Delete
                                                                </button>
                                                            </form>
                                                        @else
                                                            <!-- User Actions -->
                                                            @if($booking->Status !== 'cancelled')
                                                                <form method="POST" action="{{ route('user.bookings.destroy', $booking->Booking_ID) }}" 
                                                                      class="d-inline" onsubmit="return confirm('Are you sure you want to cancel this booking?')">
                                                                    @csrf
                                                                    @method('DELETE')
                                                                    <button type="submit" class="btn btn-sm btn-outline-danger">
                                                                        <i class="fas fa-times me-1"></i>Cancel
                                                                    </button>
                                                                </form>
                                                            @endif
                                                        @endif
                                                    </div>
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
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
