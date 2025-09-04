// src/components/pages/AvailableCoursesPage.js

import React, { useEffect, useState } from 'react';
import '../css/Courses.css';
import { useNavigate } from 'react-router-dom';
import { getSchedules } from '../api/schedules';
import Footer from '../Footer'; // ✅ Importing the Footer

function AvailableCoursesPage() {
  const [schedules, setSchedules] = useState([]);
  const navigate = useNavigate();

  useEffect(() => {
    getSchedules()
      .then(res => setSchedules(res.data))
      .catch(err => console.error('Error fetching schedules:', err));
  }, []);

  const handleApply = (courseId) => {
    navigate(`/apply?courseId=${courseId}`);
  };

  return (
    <div className="available-courses-page">
      {/* Hero Section */}
      <div className="hero-courses">
        <div className="overlay">
          <h1 className="fade-in-up">Available Courses</h1>
          <p className="fade-in-up delay-1">
            Explore top-tier programs designed by industry-leading instructors. Enroll today!
          </p>
        </div>
      </div>

      {/* Intro Section */}
      <section className="courses-intro fade-in-up">
        <h2>Choose from a Variety of World-Class Courses</h2>
        <p>Whether you're diving into technology, business, or science — we have the right course for you.</p>
      </section>

      {/* Courses List Section */}
      <section className="course-list-section fade-in" id="list">
        <div className="course-grid">
          {schedules.length === 0 ? (
            <p className="loading-text">Loading courses...</p>
          ) : (
            schedules.map((schedule) => (
              <div className="course-card" key={schedule.schedule_id}>
                <h2 className="course-title">
                  💻 {schedule.course?.course_name || 'Untitled'}
                </h2>

                <div className="course-info"><strong>👨‍🏫 Instructor:</strong> {schedule.instructor?.name || 'N/A'}</div>
                <div className="course-info"><strong>🎓 Department:</strong> {schedule.course?.department?.department_name || 'N/A'}</div>
                <div className="course-info"><strong>🕒 Schedule:</strong> {schedule.day_of_week} · {schedule.start_time?.slice(0,5)}–{schedule.end_time?.slice(0,5)}</div>
                <div className="course-info"><strong>🏫 Room:</strong> {schedule.classroom?.room_number || 'N/A'}</div>

                <button className="apply-button" onClick={() => handleApply(schedule.course?.course_id)}>
                  🔷 Apply Now
                </button>
              </div>
            ))
          )}
        </div>
      </section>

      {/* ✅ Footer at the bottom */}
      <Footer />
    </div>
  );
}

export default AvailableCoursesPage;