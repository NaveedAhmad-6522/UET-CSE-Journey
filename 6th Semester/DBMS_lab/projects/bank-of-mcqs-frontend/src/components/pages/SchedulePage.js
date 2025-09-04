import React, { useState, useEffect } from 'react';
import { getSchedules, addSchedule, updateSchedule, deleteSchedule } from '../api/schedules';
import { getCourses } from '../api/courses';
import { getClassrooms } from '../api/classrooms';
import { getInstructors } from '../api/instructors'; // ✅ Make sure this file exists
import '../css/SchedulePage.css';
function SchedulePage() {
  const [schedules, setSchedules] = useState([]);
  const [courses, setCourses] = useState([]);
  const [classrooms, setClassrooms] = useState([]);
  const [instructors, setInstructors] = useState([]);

  const [formData, setFormData] = useState({
    day: '',
    start_time: '',
    end_time: '',
    course_id: '',
    classroom_id: '',
    instructor_id: '',
  });

  const [editingId, setEditingId] = useState(null);

  useEffect(() => {
    fetchSchedules();
    fetchCourses();
    fetchClassrooms();
    fetchInstructors();
  }, []);

  const fetchSchedules = () => {
    getSchedules().then(res => setSchedules(res.data));
  };

  const fetchCourses = () => {
    getCourses().then(res => setCourses(res.data));
  };

  const fetchClassrooms = () => {
    getClassrooms().then(res => setClassrooms(res.data));
  };

  const fetchInstructors = () => {
    getInstructors().then(res => setInstructors(res.data));
  };

  const handleChange = e => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = e => {
    e.preventDefault();
    console.log('Submitting:', formData);

    const action = editingId
      ? updateSchedule(editingId, formData)
      : addSchedule(formData);

    action
      .then(() => {
        fetchSchedules();
        setFormData({
          day: '',
          start_time: '',
          end_time: '',
          course_id: '',
          classroom_id: '',
          instructor_id: '',
        });
        setEditingId(null);
      })
      .catch(err => console.error('Submission failed:', err));
  };

  const handleEdit = (schedule) => {
    setFormData({
      day: schedule.day_of_week,
      start_time: schedule.start_time,
      end_time: schedule.end_time,
      course_id: String(schedule.course_id),
      classroom_id: String(schedule.classroom_id),
      instructor_id: String(schedule.instructor_id),
    });
    setEditingId(schedule.schedule_id);
  };

  const handleDelete = (id) => {
    deleteSchedule(id).then(fetchSchedules);
  };

  return (
    <div className="schedule-container">
      <h2>Schedule Management</h2>
      <form onSubmit={handleSubmit} className="schedule-form">
        <div>
          <label>Day</label>
          <input name="day" value={formData.day} onChange={handleChange} required />
        </div>
        <div>
          <label>Start Time</label>
          <input type="time" name="start_time" value={formData.start_time} onChange={handleChange} required />
        </div>
        <div>
          <label>End Time</label>
          <input type="time" name="end_time" value={formData.end_time} onChange={handleChange} required />
        </div>
        <div>
          <label>Course</label>
          <select name="course_id" value={formData.course_id} onChange={handleChange} required>
            <option value="">Select Course</option>
            {courses.map(course => (
              <option key={course.course_id} value={course.course_id}>
                {course.course_name}
              </option>
            ))}
          </select>
        </div>
        <div>
          <label>Classroom</label>
          <select name="classroom_id" value={formData.classroom_id} onChange={handleChange} required>
            <option value="">Select Classroom</option>
            {classrooms.map(room => (
              <option key={room.classroom_id} value={room.classroom_id}>
                {room.room_number}
              </option>
            ))}
          </select>
        </div>
        <div>
          <label>Instructor</label>
          <select name="instructor_id" value={formData.instructor_id} onChange={handleChange} required>
          <option value="">Select Instructor</option>
            {instructors.map(inst => (
              <option key={inst.instructor_id} value={inst.instructor_id}>
                {inst.name}
              </option>
            ))}
          </select>
        </div>
        <button type="submit">{editingId ? 'Update' : 'Add'} Schedule</button>
      </form>

      <div className="schedule-list">
  {schedules.map(schedule => (
    <div key={schedule.schedule_id} className="schedule-card">
      <div className="schedule-info">
        <p><strong>{schedule.day_of_week}</strong> | {schedule.start_time} - {schedule.end_time}</p>
        <p>📘 <strong>Course:</strong> {schedule.course?.course_name || schedule.course_id}</p>
        <p>🏫 <strong>Classroom:</strong> {schedule.classroom?.room_number || schedule.classroom_id}</p>
        <p>👨‍🏫 <strong></strong> Instructor: {schedule.instructor?.name || schedule.instructor_id}</p>
      </div>
      <div className="schedule-actions">
        <button className="edit-btn" onClick={() => handleEdit(schedule)}>Edit</button>
        <button className="delete-btn" onClick={() => handleDelete(schedule.schedule_id)}>Delete</button>
      </div>
    </div>
  ))}
</div>
    </div>
  );
}

export default SchedulePage;