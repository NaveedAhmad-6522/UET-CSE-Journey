<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use Symfony\Component\HttpFoundation\Response;

class AdminMiddleware
{
    /**
     * Handle an incoming request.
     *
     * @param  \Closure(\Illuminate\Http\Request): (\Symfony\Component\HttpFoundation\Response)  $next
     */
    public function handle(Request $request, Closure $next): Response
    {
        if (!auth()->check()) {
            return redirect('/admin/login')->with('error', 'Please login as admin to access this page.');
        }

        if (!auth()->user()->isAdmin()) {
            // If user is not admin, redirect them to their appropriate dashboard
            if (auth()->user()->isPassenger()) {
                return redirect('/dashboard')->with('error', 'Access denied. Admin privileges required.');
            } else {
                return redirect('/')->with('error', 'Access denied. Admin privileges required.');
            }
        }

        return $next($request);
    }
}
