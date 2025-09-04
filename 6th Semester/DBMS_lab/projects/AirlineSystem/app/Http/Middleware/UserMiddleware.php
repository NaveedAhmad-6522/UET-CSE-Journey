<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use Symfony\Component\HttpFoundation\Response;

class UserMiddleware
{
    /**
     * Handle an incoming request.
     *
     * @param  \Closure(\Illuminate\Http\Request): (\Symfony\Component\HttpFoundation\Response)  $next
     */
    public function handle(Request $request, Closure $next): Response
    {
        if (!auth()->check()) {
            return redirect('/login')->with('error', 'Please login to access this page.');
        }

        // Prevent admins from accessing user routes
        if (auth()->user()->isAdmin()) {
            return redirect('/admin/dashboard')->with('error', 'Admins should use the admin panel.');
        }

        return $next($request);
    }
} 