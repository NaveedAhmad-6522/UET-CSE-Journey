<!DOCTYPE html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="csrf-token" content="{{ csrf_token() }}">

        <title>{{ config('app.name', 'SkyWay Airlines') }}</title>

        <!-- Fonts -->
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&display=swap" rel="stylesheet">
        
        <!-- Font Awesome -->
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">

        <!-- Scripts -->
        @vite(['resources/css/app.css', 'resources/js/app.js'])
    </head>
    <body class="antialiased">
        <div class="min-vh-100 d-flex flex-column">
            @include('layouts.navigation')

            <!-- Page Heading -->
            @isset($header)
                <header class="bg-white shadow-sm border-bottom">
                    <div class="container py-4">
                        <h1 class="h3 mb-0 text-dark">{{ $header }}</h1>
                    </div>
                </header>
            @endisset

            <!-- Page Content -->
            <main class="flex-grow-1">
                {{ $slot }}
            </main>
            
            <!-- Footer -->
            <footer class="bg-dark text-white py-4 mt-auto">
                <div class="container">
                    <div class="row align-items-center">
                        <div class="col-md-6">
                            <h5 class="mb-0">
                                <i class="fas fa-plane me-2"></i>SkyWay Airlines
                            </h5>
                            <p class="mb-0 text-muted">Your trusted partner in air travel.</p>
                        </div>
                        <div class="col-md-6 text-md-end">
                            <p class="mb-0">&copy; {{ date('Y') }} SkyWay Airlines. All rights reserved.</p>
                        </div>
                    </div>
                </div>
            </footer>
        </div>
    </body>
</html>
