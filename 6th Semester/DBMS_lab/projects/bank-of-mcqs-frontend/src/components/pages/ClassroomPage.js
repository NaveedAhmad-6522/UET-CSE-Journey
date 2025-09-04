import React, { useState, useEffect } from 'react';
import { getClassrooms, addClassroom, updateClassroom, deleteClassroom } from '../api/classrooms';
import { getDepartments } from '../api/department';

import '../css/ClassroomPage.css';
function ClassroomPage() {
  const [classrooms, setClassrooms] = useState([]);
  const [departments, setDepartments] = useState([]);
  const [filterDeptId, setFilterDeptId] = useState('');  // For filtering classrooms by department
  const [formData, setFormData] = useState({
    room_number: '',
    capacity: '',
    department_id: ''
  });
  const [editingId, setEditingId] = useState(null);

  useEffect(() => {
    fetchDepartments();
    fetchClassrooms();
  }, []);

  // Fetch all departments from API
const fetchDepartments = () => {
    getDepartments()
      .then(res => {
        console.log('Departments:', res.data);
        setDepartments(res.data);
      })
      .catch(err => {
        console.error('Failed to load departments:', err);
      
      });
  };
  // Fetch classrooms
  const fetchClassrooms = () => {
    getClassrooms()
      .then(res => {
        console.log('Classrooms fetched:', res.data);
        setClassrooms(res.data);
      })
      .catch(err => console.error('Error fetching classrooms:', err));
  };

  const handleChange = e => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = e => {
    e.preventDefault();
    const action = editingId ? updateClassroom(editingId, formData) : addClassroom(formData);
    action.then(() => {
      fetchClassrooms();
      setFormData({ room_number: '', capacity: '', department_id: '' });
      setEditingId(null);
    });
  };

  const handleEdit = (classroom) => {
    setFormData({
      room_number: classroom.room_number,
      capacity: classroom.capacity,
      department_id: String(classroom.department_id), // normalize to string
    });
    setEditingId(classroom.classroom_id);
  };

  const handleDelete = (id) => {
    deleteClassroom(id).then(fetchClassrooms);
  };

  // Filter classrooms by selected department, normalizing IDs to string for consistent comparison
  const filteredClassrooms = filterDeptId
    ? classrooms.filter(c => String(c.department_id) === String(filterDeptId))
    : classrooms;

  return (
    <div className="classroom-container">
      <h2>Classroom Management</h2>

      {/* Filter classrooms by department */}
      <div>
        <label>Filter by Department: </label>
        <select value={filterDeptId} onChange={e => setFilterDeptId(e.target.value)}>
          <option value="">All Departments</option>
          {departments.map(dept => (
  <option key={dept.department_id} value={String(dept.department_id)}>
    {dept.department_name}
  </option>
))}
    
        </select>
      </div>

      {/* Add / Update Classroom form */}
      <form onSubmit={handleSubmit} className="classroom-form" style={{ marginTop: '1rem' }}>
        <div>
          <label>Room Number</label>
          <input name="room_number" value={formData.room_number} onChange={handleChange} required />
        </div>
        <div>
          <label>Capacity</label>
          <input type="number" name="capacity" value={formData.capacity} onChange={handleChange} required />
        </div>
        <div>
          <label>Department</label>
          

<select name="department_id" value={formData.department_id} onChange={handleChange} required>
  <option value="">Select Department</option>
  {departments.map(dept => (
    <option key={dept.department_id} value={String(dept.department_id)}>
      {dept.department_name}  {/* ✅ Correct Field */}
    </option>
  ))}
</select>
        </div>
        <button type="submit">{editingId ? 'Update' : 'Add'} Classroom</button>
      </form>

      {/* Classroom list */}
      <ul className="classroom-list">
  {filteredClassrooms.map(classroom => {
    const dept = departments.find(d => String(d.department_id) === String(classroom.department_id));
    return (
      <li key={classroom.classroom_id} className="classroom-item">
        <div className="classroom-info">
          <strong>Room:</strong> {classroom.room_number} | 
          <strong> Capacity:</strong> {classroom.capacity} | 
          <strong> Dept:</strong> {dept ? dept.department_name : 'N/A'}
        </div>
        <div className="classroom-actions">
          <button onClick={() => handleEdit(classroom)} className="edit-btn">Edit</button>
          <button onClick={() => handleDelete(classroom.classroom_id)} className="delete-btn">Delete</button>
        </div>
      </li>
    );
  })}
</ul>
    </div>
  );
}




export default ClassroomPage;