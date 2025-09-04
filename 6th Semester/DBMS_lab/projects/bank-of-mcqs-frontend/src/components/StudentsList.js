import React, { useEffect, useState } from 'react';
import axios from 'axios';

function StudentsList() {
  const [students, setStudents] = useState([]);

  useEffect(() => {
    axios.get('https://uetapi.bomseries.shop/api/students')
      .then(res => setStudents(res.data))
      .catch(err => console.error('API error:', err));
  }, []);

  return (
    <div>
      <h2>Students</h2>
      <ul>
        {students.map(student => (
          <li key={student.student_id}>
            {student.first_name} {student.last_name} — {student.email}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default StudentsList;