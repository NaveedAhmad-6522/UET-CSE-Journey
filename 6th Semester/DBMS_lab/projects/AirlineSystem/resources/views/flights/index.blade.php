<!DOCTYPE html>
<html>
<head>
    <title>Flight List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Flights</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.flights.create') }}" class="btn btn-primary mb-3">Add Flight</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Airline Name</th>
                <th>Source</th>
                <th>Destination</th>
                <th>Departure Time</th>
                <th>Arrival Time</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($flights as $flight)
            <tr>
                <td>{{ $flight->Airline_Name }}</td>
                <td>{{ $flight->Source }}</td>
                <td>{{ $flight->Destination }}</td>
                <td>{{ $flight->Departure_Time }}</td>
                <td>{{ $flight->Arrival_Time }}</td>
                <td>
                    @if(isset($flight->Flight_ID) || isset($flight->id))
                        <a href="{{ route('admin.flights.edit', $flight->Flight_ID ?? $flight->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.flights.destroy', $flight->Flight_ID ?? $flight->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Flight (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html> 
