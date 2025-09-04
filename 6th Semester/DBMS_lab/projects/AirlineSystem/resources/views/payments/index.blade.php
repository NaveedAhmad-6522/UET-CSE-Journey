<!DOCTYPE html>
<html>
<head>
    <title>Payment List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Payments</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.payments.create') }}" class="btn btn-primary mb-3">Add Payment</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Booking ID</th>
                <th>Amount</th>
                <th>Payment Date</th>
                <th>Payment Method</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($payments as $payment)
            <tr>
                <td>{{ $payment->booking_id }}</td>
                <td>${{ number_format($payment->amount, 2) }}</td>
                <td>{{ $payment->payment_date }}</td>
                <td>{{ $payment->payment_method }}</td>
                <td>
                    @if(isset($payment->Payment_ID) || isset($payment->id))
                        <a href="{{ route('admin.payments.edit', $payment->Payment_ID ?? $payment->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.payments.destroy', $payment->Payment_ID ?? $payment->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Payment (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
