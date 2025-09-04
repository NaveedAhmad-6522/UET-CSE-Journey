<!DOCTYPE html>
<html>
<head>
    <title>Create Staff</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Create Staff</h1>

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

    <form method="POST" action="{{ route('admin.staff.store') }}" class="card p-4 shadow-sm bg-white">
        @csrf
        <div class="mb-3">
            <label class="form-label">Name:</label>
            <input type="text" name="name" class="form-control" value="{{ old('name') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Role:</label>
            <select name="role" class="form-control" required>
                <option value="">Select Role</option>
                <option value="Pilot" {{ old('role') == 'Pilot' ? 'selected' : '' }}>Pilot</option>
                <option value="Flight Attendant" {{ old('role') == 'Flight Attendant' ? 'selected' : '' }}>Flight Attendant</option>
                <option value="Ground Staff" {{ old('role') == 'Ground Staff' ? 'selected' : '' }}>Ground Staff</option>
                <option value="Engineer" {{ old('role') == 'Engineer' ? 'selected' : '' }}>Engineer</option>
            </select>
        </div>
        <div class="mb-3">
            <label class="form-label">Contact Number:</label>
            <input type="text" name="contact_number" class="form-control" value="{{ old('contact_number') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Assigned Flight ID (optional):</label>
            <input type="number" name="assigned_flight_id" class="form-control" value="{{ old('assigned_flight_id') }}">
        </div>
        <button type="submit" class="btn btn-primary">Save</button>
        <a href="{{ route('admin.staff.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html> 
