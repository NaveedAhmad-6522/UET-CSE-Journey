// src/components/pages/IndexPage.js
import React from 'react';
import { NavLink } from 'react-router-dom';
import '../css/Main.css';

function IndexPage() {
  return (
    <div className="harvard-landing">
      {/* Hero Section */}
      <div className="hero-section">
        <div className="overlay">
          <h1 className="fade-in">Harvard Course Registration</h1>
          <p className="fade-in delay-1">
            Your journey to academic excellence begins here. Explore, choose, and apply for world-class courses.
          </p>
          <NavLink to="/courses" className="hero-button">View Available Courses</NavLink>
        </div>
      </div>

      {/* Information Section */}
      <section className="info-section">
  <div className="info-box">
    <h2>Apply for Courses</h2>
    <p>Start your application journey and enroll in the courses that match your goals.</p>
    <NavLink to="/courses" className="info-link">Start Applying</NavLink>
  </div>

  <div className="info-box">
    <h2>Available Courses</h2>
    <p>Browse a wide range of top-quality courses taught by expert instructors.</p>
    <NavLink to="/courses" className="info-link">Browse Courses</NavLink>
  </div>

  <div className="info-box">
    <h2>Class Schedules</h2>
    <p>Check the timing and location of your selected classes and manage your calendar.</p>
    <NavLink to="/courses" className="info-link">Schedule</NavLink>
  </div>
</section>
      

      {/* Footer Banner */}
      <section className="footer-banner">
        <h2>Join the Legacy</h2>
        <p>Harvard’s academic excellence awaits. Enroll today.</p>
        <NavLink to="/students" className="hero-button small">Start Application</NavLink>
      </section>
    </div>
  );
}

export default IndexPage;