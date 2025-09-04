import './bootstrap';
import 'bootstrap/dist/js/bootstrap.bundle.min.js';

// Custom JavaScript for the airline system
document.addEventListener('DOMContentLoaded', function() {
    console.log('SkyWay Airlines - Application loaded successfully!');
    
    // Initialize tooltips
    var tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'));
    var tooltipList = tooltipTriggerList.map(function (tooltipTriggerEl) {
        return new bootstrap.Tooltip(tooltipTriggerEl);
    });
    
    // Initialize popovers
    var popoverTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="popover"]'));
    var popoverList = popoverTriggerList.map(function (popoverTriggerEl) {
        return new bootstrap.Popover(popoverTriggerEl);
    });
    
    // Add fade-in animation to cards
    const cards = document.querySelectorAll('.card, .feature-card, .flight-card');
    const observer = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('fade-in');
            }
        });
    });
    
    cards.forEach(card => {
        observer.observe(card);
    });
    
    // Form validation enhancement
    const forms = document.querySelectorAll('.needs-validation');
    forms.forEach(form => {
        form.addEventListener('submit', function(event) {
            if (!form.checkValidity()) {
                event.preventDefault();
                event.stopPropagation();
            }
            form.classList.add('was-validated');
        });
    });
    
    // Dynamic price calculation for flight booking
    const passengerCountSelect = document.getElementById('passengerCount');
    const seatClassSelect = document.getElementById('seatClass');
    const totalPriceElement = document.getElementById('totalPrice');
    
    if (passengerCountSelect && seatClassSelect && totalPriceElement) {
        function updateTotalPrice() {
            const passengerCount = parseInt(passengerCountSelect.value);
            const seatClass = seatClassSelect.value;
            const basePrice = 299; // Default base price
            
            let multiplier = 1;
            switch(seatClass) {
                case 'economy':
                    multiplier = 1;
                    break;
                case 'premium':
                    multiplier = 1.5;
                    break;
                case 'business':
                    multiplier = 2.5;
                    break;
            }
            
            const taxes = 25;
            const total = (basePrice * multiplier + taxes) * passengerCount;
            totalPriceElement.textContent = '$' + total.toFixed(2);
        }
        
        passengerCountSelect.addEventListener('change', updateTotalPrice);
        seatClassSelect.addEventListener('change', updateTotalPrice);
        updateTotalPrice(); // Initial calculation
    }
    
    // Smooth scrolling for anchor links
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function (e) {
            e.preventDefault();
            const target = document.querySelector(this.getAttribute('href'));
            if (target) {
                target.scrollIntoView({
                    behavior: 'smooth',
                    block: 'start'
                });
            }
        });
    });
    
    // Loading state for buttons
    document.querySelectorAll('.btn').forEach(button => {
        button.addEventListener('click', function() {
            if (this.type === 'submit') {
                this.classList.add('loading');
                this.innerHTML = '<span class="spinner-border spinner-border-sm me-2" role="status" aria-hidden="true"></span>Loading...';
            }
        });
    });
    
    // Auto-hide alerts after 5 seconds
    const alerts = document.querySelectorAll('.alert');
    alerts.forEach(alert => {
        setTimeout(() => {
            if (alert.parentNode) {
                alert.style.transition = 'opacity 0.5s ease';
                alert.style.opacity = '0';
                setTimeout(() => {
                    if (alert.parentNode) {
                        alert.remove();
                    }
                }, 500);
            }
        }, 5000);
    });
    
    // Search form enhancement
    const searchForm = document.querySelector('form[action*="search"]');
    if (searchForm) {
        const fromSelect = searchForm.querySelector('select[name="from"]');
        const toSelect = searchForm.querySelector('select[name="to"]');
        
        if (fromSelect && toSelect) {
            fromSelect.addEventListener('change', function() {
                // Disable the same option in destination
                Array.from(toSelect.options).forEach(option => {
                    option.disabled = option.value === this.value && option.value !== '';
                });
            });
            
            toSelect.addEventListener('change', function() {
                // Disable the same option in origin
                Array.from(fromSelect.options).forEach(option => {
                    option.disabled = option.value === this.value && option.value !== '';
                });
            });
        }
    }
});

// Export for module systems
export default {};
