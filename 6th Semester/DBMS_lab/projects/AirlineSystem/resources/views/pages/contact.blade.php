<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contact Us - SkyWay Airlines</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    <style>
        .hero-section {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 80px 0;
        }
        .contact-info-card {
            background: #f8f9fa;
            border-radius: 10px;
            padding: 30px;
            height: 100%;
        }
        .contact-icon {
            font-size: 2.5rem;
            color: #667eea;
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
                        <a class="nav-link active" href="{{ route('contact') }}">Contact</a>
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
        <div class="container text-center">
            <h1 class="display-4 fw-bold mb-4">Contact Us</h1>
            <p class="lead">We're here to help! Get in touch with our team</p>
        </div>
    </section>

    <!-- Contact Information -->
    <section class="py-5">
        <div class="container">
            <div class="row g-4 mb-5">
                <div class="col-md-4">
                    <div class="contact-info-card text-center">
                        <i class="fas fa-map-marker-alt contact-icon mb-3"></i>
                        <h5>Headquarters</h5>
                        <p class="mb-0">123 Aviation Way<br>SkyCity, SC 12345<br>United States</p>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="contact-info-card text-center">
                        <i class="fas fa-phone contact-icon mb-3"></i>
                        <h5>Phone</h5>
                        <p class="mb-0">
                            Reservations: +1 (555) 123-4567<br>
                            Customer Service: +1 (555) 123-4568<br>
                            Emergency: +1 (555) 123-4569
                        </p>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="contact-info-card text-center">
                        <i class="fas fa-envelope contact-icon mb-3"></i>
                        <h5>Email</h5>
                        <p class="mb-0">
                            info@skyway.com<br>
                            support@skyway.com<br>
                            bookings@skyway.com
                        </p>
                    </div>
                </div>
            </div>

            <!-- Contact Form -->
            <div class="row">
                <div class="col-lg-8 mx-auto">
                    <div class="card shadow">
                        <div class="card-header bg-primary text-white">
                            <h4 class="mb-0"><i class="fas fa-paper-plane me-2"></i>Send us a Message</h4>
                        </div>
                        <div class="card-body p-4">
                            <form>
                                <div class="row">
                                    <div class="col-md-6 mb-3">
                                        <label for="firstName" class="form-label">First Name</label>
                                        <input type="text" class="form-control" id="firstName" required>
                                    </div>
                                    <div class="col-md-6 mb-3">
                                        <label for="lastName" class="form-label">Last Name</label>
                                        <input type="text" class="form-control" id="lastName" required>
                                    </div>
                                </div>
                                <div class="row">
                                    <div class="col-md-6 mb-3">
                                        <label for="email" class="form-label">Email Address</label>
                                        <input type="email" class="form-control" id="email" required>
                                    </div>
                                    <div class="col-md-6 mb-3">
                                        <label for="phone" class="form-label">Phone Number</label>
                                        <input type="tel" class="form-control" id="phone">
                                    </div>
                                </div>
                                <div class="mb-3">
                                    <label for="subject" class="form-label">Subject</label>
                                    <select class="form-select" id="subject" required>
                                        <option value="">Select a subject</option>
                                        <option value="booking">Booking Inquiry</option>
                                        <option value="support">Customer Support</option>
                                        <option value="feedback">Feedback</option>
                                        <option value="complaint">Complaint</option>
                                        <option value="other">Other</option>
                                    </select>
                                </div>
                                <div class="mb-3">
                                    <label for="message" class="form-label">Message</label>
                                    <textarea class="form-control" id="message" rows="5" required 
                                              placeholder="Please describe your inquiry in detail..."></textarea>
                                </div>
                                <div class="mb-3 form-check">
                                    <input type="checkbox" class="form-check-input" id="newsletter">
                                    <label class="form-check-label" for="newsletter">
                                        Subscribe to our newsletter for updates and special offers
                                    </label>
                                </div>
                                <button type="submit" class="btn btn-primary btn-lg">
                                    <i class="fas fa-paper-plane me-2"></i>Send Message
                                </button>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Office Hours -->
    <section class="py-5 bg-light">
        <div class="container">
            <div class="row">
                <div class="col-lg-6 mx-auto text-center">
                    <h3 class="mb-4">Customer Service Hours</h3>
                    <div class="row">
                        <div class="col-md-6">
                            <h5>Monday - Friday</h5>
                            <p>8:00 AM - 8:00 PM EST</p>
                        </div>
                        <div class="col-md-6">
                            <h5>Saturday - Sunday</h5>
                            <p>9:00 AM - 6:00 PM EST</p>
                        </div>
                    </div>
                    <p class="text-muted mt-3">
                        <i class="fas fa-info-circle me-1"></i>
                        Emergency support is available 24/7 for urgent travel issues.
                    </p>
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
