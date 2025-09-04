<!DOCTYPE html>
<html>
<head>
    <title>Edit Payment</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Edit Payment</h1>

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

    <form method="POST" action="{{ route('admin.payments.update', $payment->Payment_ID ?? $payment->id) }}" class="card p-4 shadow-sm bg-white">
        @csrf
        @method('PUT')
        <div class="mb-3">
            <label class="form-label">Booking ID:</label>
            <input type="number" name="booking_id" class="form-control" value="{{ old('booking_id', $payment->booking_id) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Amount:</label>
            <input type="number" step="0.01" name="amount" class="form-control" value="{{ old('amount', $payment->amount) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Payment Date:</label>
            <input type="date" name="payment_date" class="form-control" value="{{ old('payment_date', $payment->payment_date) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Payment Method:</label>
            <input type="text" name="payment_method" class="form-control" value="{{ old('payment_method', $payment->payment_method) }}" required>
        </div>
        <button type="submit" class="btn btn-primary">Update</button>
        <a href="{{ route('admin.payments.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
