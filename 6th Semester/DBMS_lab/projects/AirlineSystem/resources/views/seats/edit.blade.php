<!DOCTYPE html>
<html>
<head>
    <title>Edit Seat</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Edit Seat</h1>

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

    <form method="POST" action="{{ route('admin.seats.update', $seat->Seat_ID ?? $seat->id) }}" class="card p-4 shadow-sm bg-white">
        @csrf
        @method('PUT')
        <div class="mb-3">
            <label class="form-label">Flight ID:</label>
            <input type="number" name="flight_id" class="form-control" value="{{ old('flight_id', $seat->flight_id) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Seat Number:</label>
            <input type="text" name="seat_number" class="form-control" value="{{ old('seat_number', $seat->seat_number) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Class:</label>
            <select name="class" class="form-control" required>
                <option value="">Select Class</option>
                <option value="Economy" {{ old('class', $seat->class) == 'Economy' ? 'selected' : '' }}>Economy</option>
                <option value="Business" {{ old('class', $seat->class) == 'Business' ? 'selected' : '' }}>Business</option>
                <option value="First" {{ old('class', $seat->class) == 'First' ? 'selected' : '' }}>First</option>
            </select>
        </div>
        <div class="mb-3">
            <label class="form-label">Availability Status:</label>
            <select name="availability_status" class="form-control" required>
                <option value="">Select Status</option>
                <option value="Available" {{ old('availability_status', $seat->availability_status) == 'Available' ? 'selected' : '' }}>Available</option>
                <option value="Booked" {{ old('availability_status', $seat->availability_status) == 'Booked' ? 'selected' : '' }}>Booked</option>
                <option value="Reserved" {{ old('availability_status', $seat->availability_status) == 'Reserved' ? 'selected' : '' }}>Reserved</option>
            </select>
        </div>
        <button type="submit" class="btn btn-primary">Update</button>
        <a href="{{ route('admin.seats.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
