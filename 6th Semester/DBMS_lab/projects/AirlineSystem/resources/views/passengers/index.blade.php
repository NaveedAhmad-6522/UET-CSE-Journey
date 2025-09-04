<!DOCTYPE html>
<html>
<head>
    <title>Passenger List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Passengers</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.passengers.create') }}" class="btn btn-primary mb-3">Add Passenger</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Name</th>
                <th>Email</th>
                <th>Phone</th>
                <th>Passport No</th>
                <th>Loyalty ID</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($passengers as $passenger)
            <tr>
                <td>{{ $passenger->Name }}</td>
                <td>{{ $passenger->Email }}</td>
                <td>{{ $passenger->Phone }}</td>
                <td>{{ $passenger->Passport_No }}</td>
                <td>{{ $passenger->Loyalty_ID }}</td>
                <td>
                    @if(isset($passenger->id) || isset($passenger->Passenger_ID))
                        <a href="{{ route('admin.passengers.edit', $passenger->Passenger_ID ?? $passenger->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.passengers.destroy', $passenger->Passenger_ID ?? $passenger->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Passenger (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>

