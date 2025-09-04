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
        <div class="min-vh-100 d-flex flex-column justify-content-center align-items-center py-5" style="background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);">
            <div class="text-center mb-4">
                <a href="/" class="text-decoration-none">
                    <div class="bg-white rounded-circle d-inline-flex align-items-center justify-content-center" style="width: 80px; height: 80px; box-shadow: 0 10px 30px rgba(0,0,0,0.2);">
                        <i class="fas fa-plane fa-2x text-primary"></i>
                    </div>
                    <h4 class="text-white mt-3 mb-0">SkyWay Airlines</h4>
                </a>
            </div>

            <div class="w-100" style="max-width: 400px;">
                <div class="card border-0 shadow-lg">
                    <div class="card-body p-4">
                        {{ $slot }}
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>
