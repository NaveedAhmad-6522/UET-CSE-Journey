<section>
    <div class="mb-3">
        <h6 class="text-muted mb-2">
            <i class="fas fa-exclamation-triangle me-1"></i>Once your account is deleted, all of its resources and data will be permanently deleted. Before deleting your account, please download any data or information that you wish to retain.
        </h6>
    </div>

    <button type="button" 
            class="btn btn-danger" 
            data-bs-toggle="modal" 
            data-bs-target="#confirm-user-deletion">
        <i class="fas fa-trash me-1"></i>Delete Account
    </button>

    <!-- Delete Account Modal -->
    <div class="modal fade" id="confirm-user-deletion" tabindex="-1" aria-labelledby="confirm-user-deletion-label" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header bg-danger text-white">
                    <h5 class="modal-title" id="confirm-user-deletion-label">
                        <i class="fas fa-exclamation-triangle me-2"></i>Delete Account
                    </h5>
                    <button type="button" class="btn-close btn-close-white" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <form method="post" action="{{ route('profile.destroy') }}">
                    @csrf
                    @method('delete')
                    
                    <div class="modal-body">
                        <div class="alert alert-warning">
                            <i class="fas fa-exclamation-triangle me-1"></i>
                            <strong>Warning:</strong> This action cannot be undone.
                        </div>
                        
                        <p class="mb-3">
                            Once your account is deleted, all of its resources and data will be permanently deleted. 
                            Please enter your password to confirm you would like to permanently delete your account.
                        </p>

                        <div class="mb-3">
                            <label for="password" class="form-label">
                                <i class="fas fa-lock me-1"></i>Password
                            </label>
                            <input id="password" 
                                   name="password" 
                                   type="password" 
                                   class="form-control @error('userDeletion.password') is-invalid @enderror" 
                                   placeholder="Enter your password to confirm"
                                   required>
                            @error('userDeletion.password')
                                <div class="invalid-feedback">{{ $message }}</div>
                            @enderror
                        </div>
                    </div>
                    
                    <div class="modal-footer">
                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">
                            <i class="fas fa-times me-1"></i>Cancel
                        </button>
                        <button type="submit" class="btn btn-danger">
                            <i class="fas fa-trash me-1"></i>Delete Account
                        </button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</section>
