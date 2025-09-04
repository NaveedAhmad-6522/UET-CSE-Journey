import React, { useEffect, useState } from 'react';
import axios from 'axios';
import * as XLSX from 'xlsx';
import { saveAs } from 'file-saver';
import {
  getStudents,
  addStudent,
  updateStudent,
  deleteStudent
} from '../api/students';
import '../css/StudentPage.css';

function StudentsPage() {
  const [students, setStudents] = useState([]);
  const [departments, setDepartments] = useState([]);
  const [filteredDept, setFilteredDept] = useState('');
  const [formData, setFormData] = useState({
    first_name: '',
    last_name: '',
    registration_number: '',
    email: '',
    phone: '',
    department_id: '',
  });
  const [editingId, setEditingId] = useState(null);

  useEffect(() => {
    fetchStudents();
    fetchDepartments();
  }, []);

  const fetchStudents = () => {
    getStudents().then(res => setStudents(res.data));
  };

  const fetchDepartments = () => {
    axios.get('https://uetapi.bomseries.shop/api/departments')
      .then(res => setDepartments(res.data))
      .catch(err => console.error('Failed to fetch departments', err));
  };

  const handleChange = e => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = e => {
    e.preventDefault();
    const action = editingId
      ? updateStudent(editingId, formData)
      : addStudent(formData);

    action
      .then(() => {
        fetchStudents();
        setFormData({
          first_name: '',
          last_name: '',
          registration_number: '',
          email: '',
          phone: '',
          department_id: '',
        });
        setEditingId(null);
      })
      .catch(err => {
        console.error('Validation or server error:', err.response?.data || err.message);
        alert('Failed to save student. Please check the input.');
      });
  };

  const handleEdit = student => {
    setFormData({
      first_name: student.first_name,
      last_name: student.last_name,
      registration_number: student.registration_number || '',
      email: student.email,
      phone: student.phone,
      department_id: student.department?.department_id || '',
    });
    setEditingId(student.student_id);
  };

  const handleDelete = id => {
    deleteStudent(id).then(fetchStudents);
  };

  const exportToExcel = () => {
    const exportData = filteredStudents.map(student => ({
      'First Name': student.first_name,
      'Last Name': student.last_name,
      'Registration Number': student.registration_number,
      'Email': student.email,
      'Phone': student.phone,
      'Department': student.department?.department_name || 'N/A',
    }));

    const worksheet = XLSX.utils.json_to_sheet(exportData);
    const workbook = XLSX.utils.book_new();
    XLSX.utils.book_append_sheet(workbook, worksheet, 'Students');

    const buffer = XLSX.write(workbook, { bookType: 'xlsx', type: 'array' });
    const blob = new Blob([buffer], { type: 'application/octet-stream' });
    saveAs(blob, 'students.xlsx');
  };

  // Apply department filter
  const filteredStudents = filteredDept
    ? students.filter(s => s.department?.department_id === parseInt(filteredDept))
    : students;

  return (
    <div className="students-container">
      <h2>Students</h2>

      <form onSubmit={handleSubmit} className="student-form">
        <input name="first_name" value={formData.first_name} onChange={handleChange} placeholder="First Name" required />
        <input name="last_name" value={formData.last_name} onChange={handleChange} placeholder="Last Name" required />
        <input name="registration_number" value={formData.registration_number} onChange={handleChange} placeholder="Registration Number" required />
        <input name="email" value={formData.email} onChange={handleChange} placeholder="Email" required />
        <input name="phone" value={formData.phone} onChange={handleChange} placeholder="Phone" required />

        <select name="department_id" value={formData.department_id} onChange={handleChange} required>
          <option value="">-- Select Department --</option>
          {departments.map(dept => (
            <option key={dept.department_id} value={dept.department_id}>
              {dept.department_name}
            </option>
          ))}
        </select>

        <button type="submit">{editingId ? 'Update' : 'Add'} Student</button>
      </form>

      <div className="filter-export-bar">
        <div>
          <label>Filter by Department:&nbsp;</label>
          <select value={filteredDept} onChange={e => setFilteredDept(e.target.value)}>
            <option value="">All</option>
            {departments.map(dept => (
              <option key={dept.department_id} value={dept.department_id}>
                {dept.department_name}
              </option>
            ))}
          </select>
        </div>
        <button className="export-btn" onClick={exportToExcel}>Export to Excel</button>

      </div>

      <ul className="student-list">
        {filteredStudents.map(student => (
          <li key={student.student_id} className="student-item">
            <div className="student-info-grid">
              <div><strong>Name:</strong> {student.first_name} {student.last_name}</div>
              <div><strong>Reg#:</strong> {student.registration_number}</div>
              <div><strong>Department:</strong> {student.department?.department_name || 'N/A'}</div>
              <div><strong>Email:</strong> {student.email}</div>
              <div><strong>Phone:</strong> {student.phone}</div>
            </div>
            <div className="student-actions">
              <button className="edit-btn" onClick={() => handleEdit(student)}>Edit</button>
              <button className="delete-btn" onClick={() => handleDelete(student.student_id)}>Delete</button>
            </div>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default StudentsPage;