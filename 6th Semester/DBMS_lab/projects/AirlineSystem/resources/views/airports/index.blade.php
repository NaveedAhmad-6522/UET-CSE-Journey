<!DOCTYPE html>
<html>
<head>
    <title>Airport List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Airports</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.airports.create') }}" class="btn btn-primary mb-3">Add Airport</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Name</th>
                <th>City</th>
                <th>Country</th>
                <th>Code</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($airports as $airport)
            <tr>
                <td>{{ $airport->Name }}</td>
                <td>{{ $airport->City }}</td>
                <td>{{ $airport->Country }}</td>
                <td>{{ $airport->Code }}</td>
                <td>
                    @if(isset($airport->Airport_ID) || isset($airport->id))
                        <a href="{{ route('admin.airports.edit', $airport->Airport_ID ?? $airport->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.airports.destroy', $airport->Airport_ID ?? $airport->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Airport (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
