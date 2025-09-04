<!DOCTYPE html>
<html>
<head>
    <title>Edit Flight</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Edit Flight</h1>

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

    <form method="POST" action="{{ route('admin.flights.update', $flight->Flight_ID ?? $flight->id) }}" class="card p-4 shadow-sm bg-white">
        @csrf
        @method('PUT')
        <div class="mb-3">
            <label class="form-label">Airline Name:</label>
            <input type="text" name="Airline_Name" class="form-control" value="{{ old('Airline_Name', $flight->Airline_Name) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Source Airport ID:</label>
            <input type="number" name="Source" class="form-control" value="{{ old('Source', $flight->Source) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Destination Airport ID:</label>
            <input type="number" name="Destination" class="form-control" value="{{ old('Destination', $flight->Destination) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Departure Time:</label>
            <input type="datetime-local" name="Departure_Time" class="form-control" value="{{ old('Departure_Time', $flight->Departure_Time) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Arrival Time:</label>
            <input type="datetime-local" name="Arrival_Time" class="form-control" value="{{ old('Arrival_Time', $flight->Arrival_Time) }}" required>
        </div>
        <button type="submit" class="btn btn-primary">Update</button>
        <a href="{{ route('admin.flights.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
