<!DOCTYPE html>
<html>
<head>
    <title>Edit Baggage</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Edit Baggage</h1>

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

    <form method="POST" action="{{ route('admin.baggage.update', $baggage->Baggage_ID ?? $baggage->id) }}" class="card p-4 shadow-sm bg-white">
        @csrf
        @method('PUT')
        <div class="mb-3">
            <label class="form-label">Booking ID:</label>
            <input type="number" name="booking_id" class="form-control" value="{{ old('booking_id', $baggage->booking_id) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Weight (kg):</label>
            <input type="number" step="0.1" name="weight" class="form-control" value="{{ old('weight', $baggage->weight) }}" min="0" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Baggage Tag:</label>
            <input type="text" name="baggage_tag" class="form-control" value="{{ old('baggage_tag', $baggage->baggage_tag) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Baggage Status:</label>
            <select name="baggage_status" class="form-control" required>
                <option value="">Select Status</option>
                <option value="Checked In" {{ old('baggage_status', $baggage->baggage_status) == 'Checked In' ? 'selected' : '' }}>Checked In</option>
                <option value="In Transit" {{ old('baggage_status', $baggage->baggage_status) == 'In Transit' ? 'selected' : '' }}>In Transit</option>
                <option value="Delivered" {{ old('baggage_status', $baggage->baggage_status) == 'Delivered' ? 'selected' : '' }}>Delivered</option>
                <option value="Lost" {{ old('baggage_status', $baggage->baggage_status) == 'Lost' ? 'selected' : '' }}>Lost</option>
            </select>
        </div>
        <button type="submit" class="btn btn-primary">Update</button>
        <a href="{{ route('admin.baggage.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html> 
