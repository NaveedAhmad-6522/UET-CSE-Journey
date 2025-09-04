<!DOCTYPE html>
<html>
<head>
    <title>Create Loyalty Program</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Create Loyalty Program</h1>

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

    <form method="POST" action="{{ route('admin.loyalty_programs.store') }}" class="card p-4 shadow-sm bg-white">
        @csrf
        <div class="mb-3">
            <label class="form-label">Program Name:</label>
            <input type="text" name="program_name" class="form-control" value="{{ old('program_name') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Miles Earned:</label>
            <input type="number" name="miles_earned" class="form-control" value="{{ old('miles_earned') }}" min="0" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Membership Level:</label>
            <select name="membership_level" class="form-control" required>
                <option value="">Select Level</option>
                <option value="Bronze" {{ old('membership_level') == 'Bronze' ? 'selected' : '' }}>Bronze</option>
                <option value="Silver" {{ old('membership_level') == 'Silver' ? 'selected' : '' }}>Silver</option>
                <option value="Gold" {{ old('membership_level') == 'Gold' ? 'selected' : '' }}>Gold</option>
                <option value="Platinum" {{ old('membership_level') == 'Platinum' ? 'selected' : '' }}>Platinum</option>
            </select>
        </div>
        <button type="submit" class="btn btn-primary">Save</button>
        <a href="{{ route('admin.loyalty_programs.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html> 
