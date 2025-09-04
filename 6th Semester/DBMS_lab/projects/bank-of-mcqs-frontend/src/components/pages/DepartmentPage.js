import React, { useEffect, useState } from 'react';
import { getDepartments, addDepartment, updateDepartment, deleteDepartment } from '../api/department'; // Adjust API imports if needed
import '../css/Department.css'; // You can create a separate CSS or reuse existing styles

function DepartmentsPage() {
  const [departments, setDepartments] = useState([]);
  const [formData, setFormData] = useState({
    department_name: '',
    department_code: ''
  });
  const [editingId, setEditingId] = useState(null);

  useEffect(() => {
    fetchDepartments();
  }, []);

  const fetchDepartments = () => {
    getDepartments().then(res => setDepartments(res.data));
  };

  const handleChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    const action = editingId
      ? updateDepartment(editingId, formData)
      : addDepartment(formData);

    action.then(() => {
      fetchDepartments();
      setFormData({ department_name: '', department_code: '' });
      setEditingId(null);
    });
  };

  const handleEdit = (department) => {
    setFormData({
      department_name: department.department_name,
      department_code: department.department_code || ''
    });
    setEditingId(department.department_id);
  };

  const handleDelete = (id) => {
    deleteDepartment(id).then(fetchDepartments);
  };

  return (
    <div className="departments-container">
      <h2>Department Management</h2>

      <form onSubmit={handleSubmit} className="course-form">
        <div className="form-group">
          <label>Department Name</label>
          <input
            name="department_name"
            value={formData.department_name}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-group">
          <label>Department Code</label>
          <input
            name="department_code"
            value={formData.department_code}
            onChange={handleChange}
          />
        </div>

        <button type="submit">{editingId ? 'Update' : 'Add'} Department</button>
      </form>

      <ul className="course-list">
        {departments.map(dep => (
          <li key={dep.department_id} className="course-item">
            <div className="course-info">
              <strong>{dep.department_code || '—'}</strong> - {dep.department_name}
            </div>
            <div className="course-actions">
              <button onClick={() => handleEdit(dep)} className="edit-btn">Edit</button>
              <button onClick={() => handleDelete(dep.department_id)} className="delete-btn">Delete</button>
            </div>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default DepartmentsPage;