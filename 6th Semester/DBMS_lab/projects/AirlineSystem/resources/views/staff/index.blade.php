<!DOCTYPE html>
<html>
<head>
    <title>Staff List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Staff</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.staff.create') }}" class="btn btn-primary mb-3">Add Staff</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Name</th>
                <th>Role</th>
                <th>Contact Number</th>
                <th>Assigned Flight ID</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($staff as $member)
            <tr>
                <td>{{ $member->Name }}</td>
                <td>
                    <span class="badge bg-info">{{ $member->Role }}</span>
                </td>
                <td>{{ $member->Contact_Number }}</td>
                <td>{{ $member->Assigned_Flight_ID ?? 'Not Assigned' }}</td>
                <td>
                    @if(isset($member->Staff_ID) || isset($member->id))
                        <a href="{{ route('admin.staff.edit', $member->Staff_ID ?? $member->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.staff.destroy', $member->Staff_ID ?? $member->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Staff (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>

