// Counter Animation
const counters = document.querySelectorAll('.counter');

function animateCounter(counter) {
    const target = parseInt(counter.getAttribute('data-target'));
    let count = 0;
    const speed = Math.ceil(target / 100);

    function updateCount() {
        if (count < target) {
            count += speed;
            if (count > target) count = target;
            counter.innerText = count;
            requestAnimationFrame(updateCount);
        }
    }

    updateCount();
}

// Trigger counter animation when element is in viewport
const observerOptions = {
    threshold: 0.5
};

const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            animateCounter(entry.target);
            observer.unobserve(entry.target);
        }
    });
}, observerOptions);

counters.forEach(counter => {
    observer.observe(counter);
});

// Doctors Data
const doctors = [
    {
        name: 'Dr. Sarah Johnson',
        specialty: 'Cardiologist',
        image: 'images/doctor1.jpg'
    },
    {
        name: 'Dr. Michael Chen',
        specialty: 'Neurologist',
        image: 'images/doctor2.jpg'
    },
    {
        name: 'Dr. Emily Brown',
        specialty: 'Pediatrician',
        image: 'images/doctor3.jpg'
    }
];

// Load Doctors
const doctorsList = document.getElementById('doctorsList');
doctors.forEach(doctor => {
    const doctorElement = document.createElement('div');
    doctorElement.className = 'col-md-4';
    doctorElement.innerHTML = `
        <div class="doctor-card">
            <img src="${doctor.image}" alt="${doctor.name}">
            <h4>${doctor.name}</h4>
            <p>${doctor.specialty}</p>
        </div>
    `;
    doctorsList.appendChild(doctorElement);
});

// Appointment Modal
const appointmentBtn = document.getElementById('appointmentBtn');
const appointmentModal = new bootstrap.Modal(document.getElementById('appointmentModal'));

appointmentBtn.addEventListener('click', () => {
    appointmentModal.show();
});

// Form Submissions
document.getElementById('contactForm').addEventListener('submit', (e) => {
    e.preventDefault();
    alert('Thank you for your message! We will get back to you soon.');
    e.target.reset();
});

document.getElementById('appointmentForm').addEventListener('submit', (e) => {
    e.preventDefault();
    alert('Appointment booked successfully! We will confirm via email.');
    appointmentModal.hide();
    e.target.reset();
});

// Smooth Scrolling
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

// Learn More Button Animation
document.getElementById('learnMore').addEventListener('click', () => {
    document.querySelector('#services').scrollIntoView({
        behavior: 'smooth',
        block: 'start'
    });
});