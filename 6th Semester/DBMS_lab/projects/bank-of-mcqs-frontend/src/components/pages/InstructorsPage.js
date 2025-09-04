import React, { useEffect, useState } from 'react';
import {
  getInstructors,
  addInstructor,
  updateInstructor,
  deleteInstructor,
  getDepartments
} from '../api/instructors';
import '../css/InstructorsPage.css';

function InstructorsPage() {
  const [instructors, setInstructors] = useState([]);
  const [departments, setDepartments] = useState([]);
  const [formData, setFormData] = useState({ name: '', email: '', department_id: '' });
  const [editingId, setEditingId] = useState(null);
  const [error, setError] = useState('');

  useEffect(() => {
    fetchInstructors();
    fetchDepartments();
  }, []);

  const fetchInstructors = () => {
    getInstructors()
      .then(res => {
        console.log('Instructors:', res.data);
        setInstructors(res.data);
      })
      .catch(err => {
        console.error('Failed to load instructors:', err);
        setError('Failed to load instructors');
      });
  };

  const fetchDepartments = () => {
    getDepartments()
      .then(res => {
        console.log('Departments:', res.data);
        setDepartments(res.data);
      })
      .catch(err => {
        console.error('Failed to load departments:', err);
        setError('Failed to load departments');
      });
  };

  const handleChange = e => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = e => {
    e.preventDefault();
    setError('');
    const action = editingId
      ? updateInstructor(editingId, formData)
      : addInstructor(formData);

    action
      .then(() => {
        fetchInstructors();
        setFormData({ name: '', email: '', department_id: '' });
        setEditingId(null);
      })
      .catch(err => {
        console.error('Error submitting form:', err);
        if (err.response && err.response.data) {
          setError(typeof err.response.data === 'string'
            ? err.response.data
            : JSON.stringify(err.response.data));
        } else {
          setError('Error submitting form');
        }
      });
  };

  const handleEdit = (instructor) => {
    setFormData({
      name: instructor.name || '',
      email: instructor.email || '',
      department_id: instructor.department_id || '',
    });
    setEditingId(instructor.instructor_id); // <-- Use instructor_id here
  };

  const handleDelete = (id) => {
    if (!id) {
      setError('Invalid instructor ID');
      return;
    }
    deleteInstructor(id)
      .then(() => fetchInstructors())
      .catch(err => {
        console.error('Failed to delete instructor:', err);
        setError('Failed to delete instructor');
      });
  };

  return (
    <div className="instructors-container" style={{ maxWidth: '700px', margin: '2rem auto', fontFamily: "'Segoe UI', Tahoma, Geneva, Verdana, sans-serif" }}>
      <h2 style={{ textAlign: 'center', color: '#2c3e50', marginBottom: '1rem' }}>Instructors</h2>

      {error && <div style={{ color: 'red', marginBottom: '1rem' }}>Error: {error}</div>}

      <form onSubmit={handleSubmit} style={{ background: '#f9f9f9', padding: '1.5rem', borderRadius: '8px', boxShadow: '0 5px 15px rgba(0,0,0,0.05)', display: 'flex', flexDirection: 'column', gap: '1rem' }}>
        <div className="form-group" style={{ display: 'flex', flexDirection: 'column' }}>
          <label htmlFor="name" style={{ fontWeight: '600', marginBottom: '0.25rem', color: '#333' }}>Name</label>
          <input
            id="name"
            name="name"
            value={formData.name}
            onChange={handleChange}
            placeholder="Name"
            required
            style={{
              padding: '0.6rem 1rem',
              borderRadius: '4px',
              border: '1px solid #ccc',
              fontSize: '1rem',
              backgroundColor: '#fff',
              transition: 'all 0.3s ease',
            }}
            onFocus={e => e.target.style.borderColor = '#007bff'}
            onBlur={e => e.target.style.borderColor = '#ccc'}
          />
        </div>

        <div className="form-group" style={{ display: 'flex', flexDirection: 'column' }}>
          <label htmlFor="email" style={{ fontWeight: '600', marginBottom: '0.25rem', color: '#333' }}>Email</label>
          <input
            id="email"
            name="email"
            type="email"
            value={formData.email}
            onChange={handleChange}
            placeholder="Email"
            required
            style={{
              padding: '0.6rem 1rem',
              borderRadius: '4px',
              border: '1px solid #ccc',
              fontSize: '1rem',
              backgroundColor: '#fff',
              transition: 'all 0.3s ease',
            }}
            onFocus={e => e.target.style.borderColor = '#007bff'}
            onBlur={e => e.target.style.borderColor = '#ccc'}
          />
        </div>

        <div className="form-group" style={{ display: 'flex', flexDirection: 'column' }}>
          <label htmlFor="department_id" style={{ fontWeight: '600', marginBottom: '0.25rem', color: '#333' }}>Department</label>
          <select
            id="department_id"
            name="department_id"
            value={formData.department_id}
            onChange={handleChange}
            required
            style={{
              padding: '0.6rem 1rem',
              borderRadius: '4px',
              border: '1px solid #ccc',
              fontSize: '1rem',
              backgroundColor: '#fff',
              transition: 'all 0.3s ease',
              cursor: 'pointer'
            }}
            onFocus={e => e.target.style.borderColor = '#007bff'}
            onBlur={e => e.target.style.borderColor = '#ccc'}
          >
            <option value="">Select Department</option>
            {departments.map(dept => (
              <option key={dept.department_id} value={dept.department_id}>
                {dept.department_name}
              </option>
            ))}
          </select>
        </div>

        <div style={{ display: 'flex', gap: '1rem' }}>
          <button
            type="submit"
            style={{
              flexGrow: 1,
              padding: '0.75rem',
              backgroundColor: '#3498db',
              color: 'white',
              fontWeight: 'bold',
              border: 'none',
              borderRadius: '6px',
              cursor: 'pointer',
              transition: 'background-color 0.3s ease',
            }}
            onMouseEnter={e => e.target.style.backgroundColor = '#2980b9'}
            onMouseLeave={e => e.target.style.backgroundColor = '#3498db'}
          >
            {editingId ? 'Update' : 'Add'} Instructor
          </button>
          {editingId && (
            <button
              type="button"
              onClick={() => {
                setFormData({ name: '', email: '', department_id: '' });
                setEditingId(null);
                setError('');
              }}
              style={{
                padding: '0.75rem 1rem',
                backgroundColor: '#6c757d',
                color: 'white',
                border: 'none',
                borderRadius: '6px',
                cursor: 'pointer',
                transition: 'background-color 0.3s ease',
              }}
              onMouseEnter={e => e.target.style.backgroundColor = '#5a6268'}
              onMouseLeave={e => e.target.style.backgroundColor = '#6c757d'}
            >
              Cancel
            </button>
          )}
        </div>
      </form>

      <ul style={{ listStyle: 'none', padding: 0, marginTop: '2rem' }}>
        {instructors.length === 0 ? (
          <li style={{ textAlign: 'center', color: '#666' }}>No instructors found.</li>
        ) : (
          instructors.map(inst => (
            <li
              key={inst.instructor_id} // <-- updated here
              style={{
                backgroundColor: '#ffffff',
                padding: '1rem',
                border: '1px solid #e1e1e1',
                marginBottom: '1rem',
                borderRadius: '6px',
                display: 'flex',
                justifyContent: 'space-between',
                alignItems: 'center',
                boxShadow: '0 2px 8px rgba(0,0,0,0.05)',
                transition: 'transform 0.2s ease',
                cursor: 'default'
              }}
              onMouseEnter={e => e.currentTarget.style.transform = 'scale(1.02)'}
              onMouseLeave={e => e.currentTarget.style.transform = 'scale(1)'}
            >
              <div>
                <strong>{inst.name}</strong> — {inst.email} — Dept ID: {inst.department_id || 'N/A'}
              </div>
              <div>
                <button
                  onClick={() => handleEdit(inst)}
                  style={{
                    marginRight: '0.5rem',
                    backgroundColor: '#f0ad4e',
                    border: 'none',
                    color: 'white',
                    padding: '0.4rem 0.8rem',
                    borderRadius: '4px',
                    cursor: 'pointer',
                    transition: 'background-color 0.3s ease',
                  }}
                  onMouseEnter={e => e.target.style.backgroundColor = '#ec971f'}
                  onMouseLeave={e => e.target.style.backgroundColor = '#f0ad4e'}
                >
                  Edit
                </button>
                <button
                  onClick={() => handleDelete(inst.instructor_id)} // <-- updated here
                  style={{
                    backgroundColor: '#d9534f',
                    border: 'none',
                    color: 'white',
                    padding: '0.4rem 0.8rem',
                    borderRadius: '4px',
                    cursor: 'pointer',
                    transition: 'background-color 0.3s ease',
                  }}
                  onMouseEnter={e => e.target.style.backgroundColor = '#c9302c'}
                  onMouseLeave={e => e.target.style.backgroundColor = '#d9534f'}
                >
                  Delete
                </button>
              </div>
            </li>
          ))
        )}
      </ul>
    </div>
  );
}

export default InstructorsPage;