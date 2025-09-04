<?php

namespace App\Http\Controllers;

use App\Models\Payment;
use Illuminate\Http\Request;

class PaymentController extends Controller
{
    public function index()
    {
        $payments = Payment::with('booking')->get();
        return view('payments.index', compact('payments'));
    }

    public function create()
    {
        return view('payments.create');
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'booking_id' => 'required|integer|exists:bookings,Booking_ID',
            'amount' => 'required|numeric|min:0',
            'payment_date' => 'required|date',
            'payment_method' => 'required|string|max:50',
        ]);
        Payment::create($validated);
        return redirect()->route('admin.payments.index')->with('success', 'Payment created successfully.');
    }

    public function edit($id)
    {
        $payment = Payment::findOrFail($id);
        return view('payments.edit', compact('payment'));
    }

    public function update(Request $request, $id)
    {
        $validated = $request->validate([
            'booking_id' => 'required|integer|exists:bookings,Booking_ID',
            'amount' => 'required|numeric|min:0',
            'payment_date' => 'required|date',
            'payment_method' => 'required|string|max:50',
        ]);
        $payment = Payment::findOrFail($id);
        $payment->update($validated);
        return redirect()->route('admin.payments.index')->with('success', 'Payment updated successfully.');
    }

    public function destroy($id)
    {
        Payment::destroy($id);
        return redirect()->route('admin.payments.index');
    }
}
