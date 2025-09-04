<!DOCTYPE html>
<html>
    <head>
    <title>Airline Management System</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    </head>
<body class="bg-light">
    <nav class="navbar navbar-expand-lg navbar-dark bg-primary">
        <div class="container">
            <a class="navbar-brand" href="/">
                <i class="fas fa-plane me-2"></i>
                Airline Management System
            </a>
        </div>
                </nav>

    <div class="container mt-5">
        <div class="row">
            <div class="col-12 text-center mb-5">
                <h1 class="display-4 text-primary">
                    <i class="fas fa-plane-departure me-3"></i>
                    Welcome to Airline Management System
                </h1>
                <p class="lead text-muted">Professional airline operations management platform</p>
            </div>
        </div>

        <div class="row g-4">
            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-users fa-3x text-primary mb-3"></i>
                        <h5 class="card-title">Passengers</h5>
                        <p class="card-text">Manage passenger information and profiles</p>
                        <a href="{{ route('admin.passengers.index') }}" class="btn btn-primary">Manage Passengers</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-plane fa-3x text-success mb-3"></i>
                        <h5 class="card-title">Flights</h5>
                        <p class="card-text">Schedule and manage flight operations</p>
                        <a href="{{ route('admin.flights.index') }}" class="btn btn-success">Manage Flights</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-calendar-check fa-3x text-info mb-3"></i>
                        <h5 class="card-title">Bookings</h5>
                        <p class="card-text">Handle passenger reservations and bookings</p>
                        <a href="{{ route('admin.bookings.index') }}" class="btn btn-info">Manage Bookings</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-credit-card fa-3x text-warning mb-3"></i>
                        <h5 class="card-title">Payments</h5>
                        <p class="card-text">Process and track payment transactions</p>
                        <a href="{{ route('admin.payments.index') }}" class="btn btn-warning">Manage Payments</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-building fa-3x text-secondary mb-3"></i>
                        <h5 class="card-title">Airports</h5>
                        <p class="card-text">Manage airport information and details</p>
                        <a href="{{ route('admin.airports.index') }}" class="btn btn-secondary">Manage Airports</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-chair fa-3x text-dark mb-3"></i>
                        <h5 class="card-title">Seats</h5>
                        <p class="card-text">Manage seat assignments and availability</p>
                        <a href="{{ route('admin.seats.index') }}" class="btn btn-dark">Manage Seats</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-user-tie fa-3x text-primary mb-3"></i>
                        <h5 class="card-title">Staff</h5>
                        <p class="card-text">Manage airline staff and crew members</p>
                        <a href="{{ route('admin.staff.index') }}" class="btn btn-primary">Manage Staff</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-star fa-3x text-warning mb-3"></i>
                        <h5 class="card-title">Loyalty Programs</h5>
                        <p class="card-text">Manage customer loyalty and rewards</p>
                        <a href="{{ route('admin.loyalty_programs.index') }}" class="btn btn-warning">Manage Programs</a>
                    </div>
                </div>
            </div>

            <div class="col-md-4">
                <div class="card h-100 shadow-sm">
                    <div class="card-body text-center">
                        <i class="fas fa-suitcase fa-3x text-info mb-3"></i>
                        <h5 class="card-title">Baggage</h5>
                        <p class="card-text">Track and manage passenger baggage</p>
                        <a href="{{ route('admin.baggage.index') }}" class="btn btn-info">Manage Baggage</a>
                    </div>
                </div>
            </div>
        </div>

        <div class="row mt-5">
            <div class="col-12">
                <div class="card bg-primary text-white">
                    <div class="card-body text-center">
                        <h4><i class="fas fa-chart-line me-2"></i>System Overview</h4>
                        <p class="mb-0">Professional airline management system with comprehensive features for modern airline operations.</p>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <footer class="bg-dark text-white text-center py-4 mt-5">
        <div class="container">
            <p class="mb-0">&copy; 2024 Airline Management System. All rights reserved.</p>
        </div>
    </footer>
    </body>
</html>
