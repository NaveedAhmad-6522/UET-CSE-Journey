import React, { useEffect, useState } from 'react';
import axios from 'axios';
import * as XLSX from 'xlsx';
import { saveAs } from 'file-saver';
import '../css/Enrollment.css';

function RegistrationRequestsPage() {
  const [enrollments, setEnrollments] = useState([]);
  const [filter, setFilter] = useState('pending');

  useEffect(() => {
    fetchEnrollments();
  }, [filter]);

  const fetchEnrollments = async () => {
    try {
      const res = await axios.get(`https://uetapi.bomseries.shop/api/enrollments?status=${filter}`);
      setEnrollments(res.data);
    } catch (err) {
      console.error("Failed to fetch enrollments:", err);
    }
  };

  const updateStatus = async (id, newStatus) => {
    try {
      await axios.put(`https://uetapi.bomseries.shop/api/enrollments/${id}`, { status: newStatus });
      fetchEnrollments();
    } catch (err) {
      if (err.response && err.response.status === 409) {
        alert(err.response.data.message);
      } else {
        console.error("Application submission failed:", err);
      }
    }
  };

  const exportToExcel = () => {
    const exportData = enrollments.map(enroll => ({
      'Enrollment ID': enroll.enrollment_id,
      'Student Name': `${enroll.student?.first_name || ''} ${enroll.student?.last_name || ''}`,
      'Registration Number': enroll.student?.registration_number || '',
      'Email': enroll.student?.email || '',
      'Phone': enroll.student?.phone || '',
      'Course': enroll.course?.course_name || '',
      'Semester': enroll.semester || '',
      'Status': enroll.status || ''
    }));

    const worksheet = XLSX.utils.json_to_sheet(exportData);
    const workbook = XLSX.utils.book_new();
    XLSX.utils.book_append_sheet(workbook, worksheet, 'Enrollments');

    const excelBuffer = XLSX.write(workbook, { bookType: 'xlsx', type: 'array' });
    const blob = new Blob([excelBuffer], { type: 'application/octet-stream' });
    saveAs(blob, `enrollments-${filter}.xlsx`);
  };

  return (
    <div className="container">
      <h2>Course Registration Requests</h2>

      <div className="controls-row">
  <div className="filter-group">
    <label htmlFor="filter">Filter by Status:</label>
    <select id="filter" value={filter} onChange={e => setFilter(e.target.value)}>
      <option value="pending">Pending</option>
      <option value="approved">Approved</option>
      <option value="rejected">Rejected</option>
    </select>
  </div>
  <button onClick={exportToExcel} className="export-btn">📥 Export to Excel</button>
</div>
      {enrollments.length === 0 ? (
        <p>No {filter} enrollments.</p>
      ) : (
        <table border="1" cellPadding="10" style={{ width: '100%', borderCollapse: 'collapse' }}>
          <thead>
            <tr>
              <th>ID</th>
              <th>Student Name</th>
              <th>Reg. Number</th>
              <th>Email</th>
              <th>Phone</th>
              <th>Course</th>
              <th>Semester</th>
              <th>Status</th>
              {filter === 'pending' && <th>Actions</th>}
            </tr>
          </thead>
          <tbody>
            {enrollments.map(enroll => (
              <tr key={enroll.enrollment_id}>
                <td>{enroll.enrollment_id}</td>
                <td>{enroll.student?.first_name} {enroll.student?.last_name}</td>
                <td>{enroll.student?.registration_number}</td>
                <td>{enroll.student?.email}</td>
                <td>{enroll.student?.phone}</td>
                <td>{enroll.course?.course_name}</td>
                <td>{enroll.semester || '-'}</td>
                <td><span className={`status ${enroll.status}`}>{enroll.status}</span></td>
                {filter === 'pending' && (
                  <td>
                    <button onClick={() => updateStatus(enroll.enrollment_id, 'approved')}>Approve</button>
                    <button onClick={() => updateStatus(enroll.enrollment_id, 'rejected')} style={{ marginLeft: '10px' }}>Reject</button>
                  </td>
                )}
              </tr>
            ))}
          </tbody>
        </table>
      )}
    </div>
  );
}

export default RegistrationRequestsPage;