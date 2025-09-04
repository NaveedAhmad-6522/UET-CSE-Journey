<!DOCTYPE html>
<html>
<head>
    <title>Create Seat</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Create Seat</h1>

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

    <form method="POST" action="{{ route('admin.seats.store') }}" class="card p-4 shadow-sm bg-white">
        @csrf
        <div class="mb-3">
            <label class="form-label">Flight ID:</label>
            <input type="number" name="flight_id" class="form-control" value="{{ old('flight_id') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Seat Number:</label>
            <input type="text" name="seat_number" class="form-control" value="{{ old('seat_number') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Class:</label>
            <select name="class" class="form-control" required>
                <option value="">Select Class</option>
                <option value="Economy" {{ old('class') == 'Economy' ? 'selected' : '' }}>Economy</option>
                <option value="Business" {{ old('class') == 'Business' ? 'selected' : '' }}>Business</option>
                <option value="First" {{ old('class') == 'First' ? 'selected' : '' }}>First</option>
            </select>
        </div>
        <div class="mb-3">
            <label class="form-label">Availability Status:</label>
            <select name="availability_status" class="form-control" required>
                <option value="">Select Status</option>
                <option value="Available" {{ old('availability_status') == 'Available' ? 'selected' : '' }}>Available</option>
                <option value="Booked" {{ old('availability_status') == 'Booked' ? 'selected' : '' }}>Booked</option>
                <option value="Reserved" {{ old('availability_status') == 'Reserved' ? 'selected' : '' }}>Reserved</option>
            </select>
        </div>
        <button type="submit" class="btn btn-primary">Save</button>
        <a href="{{ route('admin.seats.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html> 
