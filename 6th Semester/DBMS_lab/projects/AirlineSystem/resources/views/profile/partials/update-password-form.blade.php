<section>
    <div class="mb-3">
        <h6 class="text-muted mb-2">
            <i class="fas fa-shield-alt me-1"></i>Ensure your account is using a long, random password to stay secure.
        </h6>
    </div>

    <form method="post" action="{{ route('password.update') }}" class="mt-4">
        @csrf
        @method('put')

        <div class="mb-3">
            <label for="update_password_current_password" class="form-label">
                <i class="fas fa-key me-1"></i>Current Password
            </label>
            <input id="update_password_current_password" 
                   name="current_password" 
                   type="password" 
                   class="form-control @error('updatePassword.current_password') is-invalid @enderror" 
                   autocomplete="current-password"
                   placeholder="Enter your current password">
            @error('updatePassword.current_password')
                <div class="invalid-feedback">{{ $message }}</div>
            @enderror
        </div>

        <div class="mb-3">
            <label for="update_password_password" class="form-label">
                <i class="fas fa-lock me-1"></i>New Password
            </label>
            <input id="update_password_password" 
                   name="password" 
                   type="password" 
                   class="form-control @error('updatePassword.password') is-invalid @enderror" 
                   autocomplete="new-password"
                   placeholder="Enter your new password">
            @error('updatePassword.password')
                <div class="invalid-feedback">{{ $message }}</div>
            @enderror
        </div>

        <div class="mb-3">
            <label for="update_password_password_confirmation" class="form-label">
                <i class="fas fa-lock me-1"></i>Confirm New Password
            </label>
            <input id="update_password_password_confirmation" 
                   name="password_confirmation" 
                   type="password" 
                   class="form-control @error('updatePassword.password_confirmation') is-invalid @enderror" 
                   autocomplete="new-password"
                   placeholder="Confirm your new password">
            @error('updatePassword.password_confirmation')
                <div class="invalid-feedback">{{ $message }}</div>
            @enderror
        </div>

        <div class="d-flex align-items-center gap-3">
            <button type="submit" class="btn btn-warning">
                <i class="fas fa-save me-1"></i>Update Password
            </button>

            @if (session('status') === 'password-updated')
                <div class="alert alert-success mb-0 py-2 px-3" role="alert">
                    <i class="fas fa-check me-1"></i>Password updated successfully!
                </div>
            @endif
        </div>
    </form>
</section>
