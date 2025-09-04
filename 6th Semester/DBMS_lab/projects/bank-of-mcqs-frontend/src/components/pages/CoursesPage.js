import React, { useEffect, useState } from 'react';
import { getCourses, addCourse, updateCourse, deleteCourse, getInstructors, getDepartments } from '../api/courses';
import '../css/CoursesPage.css';

function CoursesPage() {
  const [courses, setCourses] = useState([]);
  const [instructors, setInstructors] = useState([]);
  const [departments, setDepartments] = useState([]);
  const [formData, setFormData] = useState({
    course_code: '',
    course_name: '',
    credit_hours: '',
    instructor_id: '',
    department_id: ''
  });
  const [editingId, setEditingId] = useState(null);

  useEffect(() => {
    fetchCourses();
    fetchInstructors();
    fetchDepartments();
  }, []);

  const fetchCourses = () => {
    getCourses().then(res => setCourses(res.data));
  };

  const fetchInstructors = () => {
    getInstructors().then(res => setInstructors(res.data));
  };

  const fetchDepartments = () => {
    getDepartments().then(res => setDepartments(res.data));
  };

  const handleChange = e => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = e => {
    e.preventDefault();
    const action = editingId
      ? updateCourse(editingId, formData)
      : addCourse(formData);

    action.then(() => {
      fetchCourses();
      setFormData({
        course_code: '',
        course_name: '',
        credit_hours: '',
        instructor_id: '',
        department_id: ''
      });
      setEditingId(null);
    });
  };

  const handleEdit = (course) => {
    setFormData({
      course_code: course.course_code,
      course_name: course.course_name,
      credit_hours: course.credit_hours,
      instructor_id: course.instructor_id || '',
      department_id: course.department_id || ''
    });
    setEditingId(course.course_id);
  };

  const handleDelete = (id) => {
    deleteCourse(id).then(fetchCourses);
  };

  // Group courses by department for display
  const groupedCourses = departments.map(dep => ({
    department: dep,
    courses: courses.filter(course => course.department_id === dep.department_id)
  }));

  return (
    <div className="courses-container">
      <h2>Course Management</h2>
      
      <form onSubmit={handleSubmit} className="course-form">
        <div className="form-group">
          <label>Course Code</label>
          <input
            name="course_code"
            value={formData.course_code}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Course Name</label>
          <input
            name="course_name"
            value={formData.course_name}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Credit Hours</label>
          <input
            name="credit_hours"
            type="number"
            min="0"
            value={formData.credit_hours}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Instructor</label>
          <select
            name="instructor_id"
            value={formData.instructor_id}
            onChange={handleChange}
            required
          >
            <option value="">Select Instructor</option>
            {instructors.map(inst => (
              <option key={inst.instructor_id} value={inst.instructor_id}>
                {inst.name}
              </option>
            ))}
          </select>
        </div>

        <div className="form-group">
          <label>Department</label>
          <select
            name="department_id"
            value={formData.department_id}
            onChange={handleChange}
            required
          >
            <option value="">Select Department</option>
            {departments.map(dep => (
              <option key={dep.department_id} value={dep.department_id}>
                {dep.department_name}
              </option>
            ))}
          </select>
        </div>

        <button type="submit">{editingId ? 'Update' : 'Add'} Course</button>
      </form>

      {groupedCourses.map(group => (
        <div key={group.department.department_id} className="department-section">
          <h3>{group.department.department_name}</h3>

          {group.courses.length === 0 ? (
            <p>No courses offered.</p>
          ) : (
            <ul className="course-list">
              {group.courses.map(course => (
                <li key={course.course_id} className="course-item">
                  <div className="course-info">
                    <strong>{course.course_code}</strong> - {course.course_name} ({course.credit_hours} hrs)
                    <br />
                    Instructor: {course.instructor?.name || 'N/A'}
                  </div>
                  <div className="course-actions">
                    <button onClick={() => handleEdit(course)} className="edit-btn">Edit</button>
                    <button onClick={() => handleDelete(course.course_id)} className="delete-btn">Delete</button>
                  </div>
                </li>
              ))}
            </ul>
          )}
        </div>
      ))}
    </div>
  );
}

export default CoursesPage;