<!DOCTYPE html>
<html>
<head>
    <title>Edit Airport</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Edit Airport</h1>

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

    <form method="POST" action="{{ route('admin.airports.update', $airport->Airport_ID ?? $airport->id) }}" class="card p-4 shadow-sm bg-white">
        @csrf
        @method('PUT')
        <div class="mb-3">
            <label class="form-label">Name:</label>
            <input type="text" name="name" class="form-control" value="{{ old('name', $airport->Name) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">City:</label>
            <input type="text" name="city" class="form-control" value="{{ old('city', $airport->City) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Country:</label>
            <input type="text" name="country" class="form-control" value="{{ old('country', $airport->Country) }}" required>
        </div>
        <div class="mb-3">
            <label class="form-label">Code:</label>
            <input type="text" name="code" class="form-control" value="{{ old('code', $airport->Code) }}" required>
        </div>
        <button type="submit" class="btn btn-primary">Update</button>
        <a href="{{ route('admin.airports.index') }}" class="btn btn-secondary">Cancel</a>
    </form>
</div>
</body>
</html>
