<!DOCTYPE html>
<html>
<head>
    <title>Create Airport</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Create Airport</h1>

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

    <form method="POST" action="{{ route('admin.airports.store') }}" class="card p-4 shadow-sm bg-white">
        @csrf
        <div class="mb-3">
            <label class="form-label">Name:</label>
            <input type="text" name="name" class="form-control" value="{{ old('name') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">City:</label>
            <input type="text" name="city" class="form-control" value="{{ old('city') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Country:</label>
            <input type="text" name="country" class="form-control" value="{{ old('country') }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Code:</label>
            <input type="text" name="code" class="form-control" value="{{ old('code') }}" required>
        </div>
        <button type="submit" class="btn btn-primary">Save</button>
        <a href="{{ route('admin.airports.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
