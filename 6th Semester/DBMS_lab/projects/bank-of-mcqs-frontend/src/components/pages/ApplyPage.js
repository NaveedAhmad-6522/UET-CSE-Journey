// src/components/pages/ApplyPage.js
import React, { useEffect, useState } from 'react';
import '../css/ApplyPage.css';
import { useLocation } from 'react-router-dom';
import { getSchedules } from '../api/schedules';
import axios from 'axios';

function ApplyPage() {
  const location = useLocation();
  const queryParams = new URLSearchParams(location.search);
  const courseId = queryParams.get('courseId');

  const [schedule, setSchedule] = useState(null);
  const [formData, setFormData] = useState({
    first_name: '',
    last_name: '',
    registration_number: '',
    email: '',
    phone: '',
  });

  const [submitting, setSubmitting] = useState(false);

  useEffect(() => {
    getSchedules()
      .then(res => {
        const matching = res.data.find(
          s => s.course?.course_id?.toString() === courseId
        );
        if (matching) {
          setSchedule(matching);
        }
      })
      .catch(console.error);
  }, [courseId]);

  const handleChange = e => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = async e => {
    e.preventDefault();

    if (!schedule?.course?.department?.department_id) {
      alert("Department information is missing. Please try again later.");
      return;
    }

    const submission = {
      ...formData,
      department_id: schedule.course.department.department_id,
      course_id: courseId,
    };

    try {
      setSubmitting(true);
      await axios.post('https://uetapi.bomseries.shop/api/apply', submission);
      alert('Application submitted successfully!');
      setFormData({
        first_name: '',
        last_name: '',
        registration_number: '',
        email: '',
        phone: '',
      });
    } catch (err) {
      console.error('Error submitting application:', err);
      alert('Failed to submit application.');
    } finally {
      setSubmitting(false);
    }
  };

  return (
    <div className="apply-container">
      <form className="glass-form" onSubmit={handleSubmit}>
        <h2 className="form-title">Course Registration</h2>

        {schedule && (
          <div className="course-details-box">
            <p><strong>Course:</strong> {schedule.course?.course_name}</p>
            <p><strong>Instructor:</strong> {schedule.instructor?.name}</p>
            <p><strong>Department:</strong> {schedule.course?.department?.department_name}</p>
            <p><strong>Schedule:</strong> {schedule.day_of_week} — {schedule.start_time} to {schedule.end_time}</p>
            <p><strong>Room:</strong> {schedule.classroom?.room_number}</p>
          </div>
        )}

        <div className="form-group">
          <label>First Name</label>
          <input
            type="text"
            name="first_name"
            value={formData.first_name}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Last Name</label>
          <input
            type="text"
            name="last_name"
            value={formData.last_name}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Registration Number</label>
          <input
            type="text"
            name="registration_number"
            value={formData.registration_number}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Email Address</label>
          <input
            type="email"
            name="email"
            value={formData.email}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Phone Number</label>
          <input
            type="tel"
            name="phone"
            value={formData.phone}
            onChange={handleChange}
            required
          />
        </div>

        <button type="submit" className="submit-btn" disabled={submitting}>
          {submitting ? 'Submitting...' : 'Submit Application'}
        </button>
      </form>
    </div>
  );
}

export default ApplyPage;