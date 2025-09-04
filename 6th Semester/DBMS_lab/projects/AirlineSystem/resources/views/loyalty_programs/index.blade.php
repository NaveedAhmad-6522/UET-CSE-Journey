<!DOCTYPE html>
<html>
<head>
    <title>Loyalty Program List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
    <h1 class="mb-4">Loyalty Programs</h1>
    @if (session('success'))
        <div class="alert alert-success">{{ session('success') }}</div>
    @endif
    <a href="{{ route('admin.loyalty_programs.create') }}" class="btn btn-primary mb-3">Add Loyalty Program</a>
    <table class="table table-bordered bg-white shadow-sm">
        <thead>
            <tr>
                <th>Program Name</th>
                <th>Miles Earned</th>
                <th>Membership Level</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
        @foreach ($loyaltyPrograms as $program)
            <tr>
                <td>{{ $program->Program_Name }}</td>
                <td>{{ number_format($program->Miles_Earned) }} miles</td>
                <td>
                    <span class="badge {{ $program->Membership_Level == 'Platinum' ? 'bg-dark' : ($program->Membership_Level == 'Gold' ? 'bg-warning' : ($program->Membership_Level == 'Silver' ? 'bg-secondary' : 'bg-danger')) }}">
                        {{ $program->Membership_Level }}
                    </span>
                </td>
                <td>
                    @if(isset($program->Loyalty_ID) || isset($program->id))
                        <a href="{{ route('admin.loyalty_programs.edit', $program->Loyalty_ID ?? $program->id) }}" class="btn btn-sm btn-warning">Edit</a>
                        <form action="{{ route('admin.loyalty_programs.destroy', $program->Loyalty_ID ?? $program->id) }}" method="POST" style="display:inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    @else
                        <span style="color:red">Invalid Program (Missing ID)</span>
                    @endif
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
