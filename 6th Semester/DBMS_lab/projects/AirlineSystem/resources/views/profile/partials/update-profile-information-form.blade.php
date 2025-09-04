<section>
    <div class="mb-3">
        <h6 class="text-muted mb-2">
            <i class="fas fa-info-circle me-1"></i>Update your account's profile information and email address.
        </h6>
    </div>

    <form id="send-verification" method="post" action="{{ route('verification.send') }}">
        @csrf
    </form>

    <form method="post" action="{{ route('profile.update') }}" class="mt-4">
        @csrf
        @method('patch')

        <div class="mb-3">
            <label for="name" class="form-label">
                <i class="fas fa-user me-1"></i>Full Name
            </label>
            <input id="name" 
                   name="name" 
                   type="text" 
                   class="form-control @error('name') is-invalid @enderror" 
                   value="{{ old('name', $user->name) }}" 
                   required 
                   autofocus 
                   autocomplete="name"
                   placeholder="Enter your full name">
            @error('name')
                <div class="invalid-feedback">{{ $message }}</div>
            @enderror
        </div>

        <div class="mb-3">
            <label for="email" class="form-label">
                <i class="fas fa-envelope me-1"></i>Email Address
            </label>
            <input id="email" 
                   name="email" 
                   type="email" 
                   class="form-control @error('email') is-invalid @enderror" 
                   value="{{ old('email', $user->email) }}" 
                   required 
                   autocomplete="username"
                   placeholder="Enter your email address">
            @error('email')
                <div class="invalid-feedback">{{ $message }}</div>
            @enderror

            @if ($user instanceof \Illuminate\Contracts\Auth\MustVerifyEmail && ! $user->hasVerifiedEmail())
                <div class="mt-2">
                    <div class="alert alert-warning">
                        <i class="fas fa-exclamation-triangle me-1"></i>
                        Your email address is unverified.
                        <button form="send-verification" class="btn btn-link btn-sm p-0 ms-1">
                            Click here to re-send the verification email.
                        </button>
                    </div>

                    @if (session('status') === 'verification-link-sent')
                        <div class="alert alert-success">
                            <i class="fas fa-check-circle me-1"></i>
                            A new verification link has been sent to your email address.
                        </div>
                    @endif
                </div>
            @endif
        </div>

        <div class="d-flex align-items-center gap-3">
            <button type="submit" class="btn btn-primary">
                <i class="fas fa-save me-1"></i>Save Changes
            </button>

            @if (session('status') === 'profile-updated')
                <div class="alert alert-success mb-0 py-2 px-3" role="alert">
                    <i class="fas fa-check me-1"></i>Profile updated successfully!
                </div>
            @endif
        </div>
    </form>
</section>
