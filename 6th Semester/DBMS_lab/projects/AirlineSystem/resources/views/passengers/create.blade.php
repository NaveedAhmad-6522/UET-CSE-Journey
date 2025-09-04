<!DOCTYPE html>
<html>
<head>
    <title>Create Passenger</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Create Passenger</h1>

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

    <form method="POST" action="{{ route('admin.passengers.store') }}" class="card p-4 shadow-sm bg-white">
        @csrf
        <div class="mb-3">
            <label class="form-label">Name:</label>
            <input type="text" name="Name" class="form-control" value="{{ old('Name') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Email:</label>
            <input type="email" name="Email" class="form-control" value="{{ old('Email') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Phone:</label>
            <input type="text" name="Phone" class="form-control" value="{{ old('Phone') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Passport Number:</label>
            <input type="text" name="Passport_No" class="form-control" value="{{ old('Passport_No') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Loyalty ID (optional):</label>
            <input type="text" name="Loyalty_ID" class="form-control" value="{{ old('Loyalty_ID') }}">
        </div>
        <button type="submit" class="btn btn-primary">Save</button>
        <a href="{{ route('admin.passengers.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
