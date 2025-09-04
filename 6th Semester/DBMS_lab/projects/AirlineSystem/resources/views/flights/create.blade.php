<!DOCTYPE html>
<html>
<head>
    <title>Create Flight</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Create Flight</h1>

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

    <form method="POST" action="{{ route('admin.flights.store') }}" class="card p-4 shadow-sm bg-white">
        @csrf
        <div class="mb-3">
            <label class="form-label">Airline Name:</label>
            <input type="text" name="Airline_Name" class="form-control" value="{{ old('Airline_Name') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Source Airport ID:</label>
            <input type="number" name="Source" class="form-control" value="{{ old('Source') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Destination Airport ID:</label>
            <input type="number" name="Destination" class="form-control" value="{{ old('Destination') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Departure Time:</label>
            <input type="datetime-local" name="Departure_Time" class="form-control" value="{{ old('Departure_Time') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Arrival Time:</label>
            <input type="datetime-local" name="Arrival_Time" class="form-control" value="{{ old('Arrival_Time') }}" required>
        </div>
        <button type="submit" class="btn btn-primary">Save</button>
        <a href="{{ route('admin.flights.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
