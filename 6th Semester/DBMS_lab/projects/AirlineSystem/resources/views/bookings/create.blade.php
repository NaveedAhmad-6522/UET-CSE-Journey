<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Book Flight - SkyWay Airlines</title>
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
            <div class="col-lg-8">
                <div class="card border-0 shadow-sm">
                    <div class="card-header bg-primary text-white">
                        <h4 class="mb-0"><i class="fas fa-ticket-alt me-2"></i>Book Your Flight</h4>
                    </div>
                    <div class="card-body p-4">
                        @if ($errors->any())
                            <div class="alert alert-danger">
                                <ul class="mb-0">
                                    @foreach ($errors->all() as $error)
                                        <li>{{ $error }}</li>
                                    @endforeach
                                </ul>
                            </div>
                        @endif

                        @if (session('success'))
                            <div class="alert alert-success">{{ session('success') }}</div>
                        @endif

                        <form method="POST" action="{{ route('user.bookings.store') }}">
                            @csrf
                            
                            <!-- Flight Selection -->
                            <div class="mb-4">
                                <h5 class="mb-3">Flight Details</h5>
                                @if($flight)
                                    <!-- Pre-selected flight -->
                                    <div class="card bg-light">
                                        <div class="card-body">
                                            <div class="row">
                                                <div class="col-md-6">
                                                    <h6 class="text-muted">Flight</h6>
                                                    <p class="fw-bold mb-1">{{ $flight->Airline_Name }}</p>
                                                    <p class="text-muted mb-0">
                                                        {{ $flight->departureAirport->Code ?? 'N/A' }} → {{ $flight->arrivalAirport->Code ?? 'N/A' }}
                                                    </p>
                                                </div>
                                                <div class="col-md-6">
                                                    <h6 class="text-muted">Date & Time</h6>
                                                    <p class="fw-bold mb-1">{{ $flight->Departure_Time ? $flight->Departure_Time->format('M d, Y') : 'N/A' }}</p>
                                                    <p class="text-muted mb-0">
                                                        {{ $flight->Departure_Time ? $flight->Departure_Time->format('H:i') : 'N/A' }} - {{ $flight->Arrival_Time ? $flight->Arrival_Time->format('H:i') : 'N/A' }}
                                                    </p>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                    <input type="hidden" name="flight_id" value="{{ $flight->Flight_ID }}">
                                @else
                                    <!-- Flight dropdown -->
                                    <div class="mb-3">
                                        <label class="form-label">Select Flight</label>
                                        <select name="flight_id" class="form-select" required>
                                            <option value="">Choose a flight...</option>
                                            @foreach($flights as $flightOption)
                                                <option value="{{ $flightOption->Flight_ID }}" {{ old('flight_id') == $flightOption->Flight_ID ? 'selected' : '' }}>
                                                    {{ $flightOption->Airline_Name }} - {{ $flightOption->departureAirport->Code ?? 'N/A' }} to {{ $flightOption->arrivalAirport->Code ?? 'N/A' }} 
                                                    ({{ $flightOption->Departure_Time ? $flightOption->Departure_Time->format('M d, H:i') : 'N/A' }})
                                                </option>
                                            @endforeach
                                        </select>
                                    </div>
                                @endif
                            </div>

                            <!-- Passenger Information -->
                            <div class="mb-4">
                                <h5 class="mb-3">Passenger Information</h5>
                                @if($passenger)
                                    <!-- Pre-filled passenger info -->
                                    <div class="card bg-light">
                                        <div class="card-body">
                                            <div class="row">
                                                <div class="col-md-6">
                                                    <h6 class="text-muted">Name</h6>
                                                    <p class="fw-bold mb-0">{{ $passenger->Name }}</p>
                                                </div>
                                                <div class="col-md-6">
                                                    <h6 class="text-muted">Email</h6>
                                                    <p class="fw-bold mb-0">{{ $passenger->Email }}</p>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                    <input type="hidden" name="passenger_id" value="{{ $passenger->Passenger_ID }}">
                                @else
                                    <!-- Passenger dropdown for admin -->
                                    <div class="mb-3">
                                        <label class="form-label">Select Passenger</label>
                                        <select name="passenger_id" class="form-select" required>
                                            <option value="">Choose a passenger...</option>
                                            @foreach($passengers as $passengerOption)
                                                <option value="{{ $passengerOption->Passenger_ID }}" {{ old('passenger_id') == $passengerOption->Passenger_ID ? 'selected' : '' }}>
                                                    {{ $passengerOption->Name }} ({{ $passengerOption->Email }})
                                                </option>
                                            @endforeach
                                        </select>
                                    </div>
                                @endif
                            </div>

                            <!-- Booking Details -->
                            <div class="mb-4">
                                <h5 class="mb-3">Booking Details</h5>
                                <div class="row">
                                    <div class="col-md-6">
                                        <div class="mb-3">
                                            <label class="form-label">Number of Passengers</label>
                                            <select name="passenger_count" class="form-select" required>
                                                @for($i = 1; $i <= 9; $i++)
                                                    <option value="{{ $i }}" {{ old('passenger_count', 1) == $i ? 'selected' : '' }}>
                                                        {{ $i }} {{ $i == 1 ? 'Passenger' : 'Passengers' }}
                                                    </option>
                                                @endfor
                                            </select>
                                        </div>
                                    </div>
                                    <div class="col-md-6">
                                        <div class="mb-3">
                                            <label class="form-label">Seat Class</label>
                                            <select name="seat_class" class="form-select" required>
                                                <option value="economy" {{ old('seat_class') == 'economy' ? 'selected' : '' }}>Economy Class</option>
                                                <option value="premium" {{ old('seat_class') == 'premium' ? 'selected' : '' }}>Premium Economy</option>
                                                <option value="business" {{ old('seat_class') == 'business' ? 'selected' : '' }}>Business Class</option>
                                            </select>
                                        </div>
                                    </div>
                                </div>
                                <div class="mb-3">
                                    <label class="form-label">Booking Date</label>
                                    <input type="date" name="booking_date" class="form-control" value="{{ old('booking_date', date('Y-m-d')) }}" required>
                                </div>
                            </div>

                            <div class="d-flex gap-2">
                                <button type="submit" class="btn btn-primary">
                                    <i class="fas fa-credit-card me-2"></i>Confirm Booking
                                </button>
                                <a href="{{ route('search.flights') }}" class="btn btn-outline-secondary">
                                    <i class="fas fa-arrow-left me-2"></i>Back to Search
                                </a>
                            </div>
                        </form>
                    </div>
                </div>
            </div>

            <!-- Price Summary -->
            <div class="col-lg-4">
                <div class="card border-0 shadow-sm sticky-top" style="top: 20px;">
                    <div class="card-header bg-info text-white">
                        <h5 class="mb-0"><i class="fas fa-calculator me-2"></i>Price Summary</h5>
                    </div>
                    <div class="card-body">
                        @if($flight)
                            <div class="mb-3">
                                <div class="d-flex justify-content-between">
                                    <span>Base Price:</span>
                                    <span class="fw-bold" id="base-price">${{ number_format($flight->price ?? 299, 2) }}</span>
                                </div>
                                <div class="d-flex justify-content-between">
                                    <span>Seat Class Multiplier:</span>
                                    <span id="class-multiplier">1.0x</span>
                                </div>
                                <div class="d-flex justify-content-between">
                                    <span>Taxes & Fees:</span>
                                    <span>$25.00</span>
                                </div>
                                <hr>
                                <div class="d-flex justify-content-between">
                                    <span class="fw-bold">Price per passenger:</span>
                                    <span class="fw-bold text-primary" id="price-per-passenger">${{ number_format(($flight->price ?? 299) + 25, 2) }}</span>
                                </div>
                                <div class="d-flex justify-content-between">
                                    <span class="fw-bold">Number of Passengers:</span>
                                    <span id="passenger-count">1</span>
                                </div>
                                <hr>
                                <div class="d-flex justify-content-between">
                                    <span class="fw-bold fs-5">Total Amount:</span>
                                    <span class="fw-bold text-success fs-5" id="total-amount">${{ number_format(($flight->price ?? 299) + 25, 2) }}</span>
                                </div>
                            </div>
                            <div class="alert alert-info">
                                <small>
                                    <i class="fas fa-info-circle me-1"></i>
                                    Prices are calculated in real-time based on your selections.
                                </small>
                            </div>
                        @else
                            <div class="text-center text-muted">
                                <i class="fas fa-plane fa-2x mb-2"></i>
                                <p>Select a flight to see pricing details</p>
                            </div>
                        @endif
                    </div>
                </div>
            </div>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
    
    @if($flight)
    <script>
        // Pricing configuration
        const basePrice = {{ $flight->price ?? 299 }};
        const taxes = 25;
        const classMultipliers = {
            'economy': 1.0,
            'premium': 1.5,
            'business': 2.5
        };

        // Get form elements
        const passengerCountSelect = document.querySelector('select[name="passenger_count"]');
        const seatClassSelect = document.querySelector('select[name="seat_class"]');

        // Function to calculate and update pricing
        function updatePricing() {
            const passengerCount = parseInt(passengerCountSelect.value);
            const seatClass = seatClassSelect.value;
            const multiplier = classMultipliers[seatClass];
            
            // Calculate price per passenger
            const pricePerPassenger = (basePrice * multiplier) + taxes;
            const totalAmount = pricePerPassenger * passengerCount;
            
            // Update display
            document.getElementById('class-multiplier').textContent = multiplier + 'x';
            document.getElementById('price-per-passenger').textContent = '$' + pricePerPassenger.toFixed(2);
            document.getElementById('passenger-count').textContent = passengerCount;
            document.getElementById('total-amount').textContent = '$' + totalAmount.toFixed(2);
        }

        // Add event listeners
        if (passengerCountSelect) {
            passengerCountSelect.addEventListener('change', updatePricing);
        }
        if (seatClassSelect) {
            seatClassSelect.addEventListener('change', updatePricing);
        }

        // Initialize pricing on page load
        updatePricing();
    </script>
    @endif
</body>
</html>
