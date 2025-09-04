<!DOCTYPE html>
<html>
<head>
    <title>Seat List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Seats</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.seats.create') }}" class="btn btn-primary mb-3">Add Seat</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Flight ID</th>
                <th>Seat Number</th>
                <th>Class</th>
                <th>Availability Status</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($seats as $seat)
            <tr>
                <td>{{ $seat->Flight_ID }}</td>
                <td>{{ $seat->Seat_Number }}</td>
                <td>{{ $seat->Class }}</td>
                <td>
                    <span class="badge {{ $seat->Availability_Status == 'Available' ? 'bg-success' : ($seat->Availability_Status == 'Booked' ? 'bg-danger' : 'bg-warning') }}">
                        {{ $seat->Availability_Status }}
                    </span>
                </td>
                <td>
                    @if(isset($seat->Seat_ID) || isset($seat->id))
                        <a href="{{ route('admin.seats.edit', $seat->Seat_ID ?? $seat->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.seats.destroy', $seat->Seat_ID ?? $seat->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Seat (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
