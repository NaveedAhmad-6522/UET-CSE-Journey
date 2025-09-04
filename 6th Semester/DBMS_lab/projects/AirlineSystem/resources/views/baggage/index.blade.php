<!DOCTYPE html>
<html>
<head>
    <title>Baggage List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Baggage</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.baggage.create') }}" class="btn btn-primary mb-3">Add Baggage</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Booking ID</th>
                <th>Weight (kg)</th>
                <th>Baggage Tag</th>
                <th>Status</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($baggage as $item)
            <tr>
                <td>{{ $item->Booking_ID }}</td>
                <td>{{ $item->Weight }} kg</td>
                <td>{{ $item->Baggage_Tag }}</td>
                <td>
                    <span class="badge {{ $item->Baggage_Status == 'Delivered' ? 'bg-success' : ($item->Baggage_Status == 'Lost' ? 'bg-danger' : ($item->Baggage_Status == 'In Transit' ? 'bg-warning' : 'bg-info')) }}">
                        {{ $item->Baggage_Status }}
                    </span>
                </td>
                <td>
                    @if(isset($item->Baggage_ID) || isset($item->id))
                        <a href="{{ route('admin.baggage.edit', $item->Baggage_ID ?? $item->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.baggage.destroy', $item->Baggage_ID ?? $item->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Baggage (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
