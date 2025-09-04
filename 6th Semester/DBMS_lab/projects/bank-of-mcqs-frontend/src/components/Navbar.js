import React from 'react';
import { NavLink } from 'react-router-dom';
import './css/navbar.css';

export default function Navbar() {
  return (
    <nav className="navbar">
      <div className="navbar-logo">Course Registration</div>
      <div className="navbar-links">
        <NavLink to="/admin/students" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
          Students
        </NavLink>
        <NavLink to="/admin/courses" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
          Courses
        </NavLink>
        <NavLink to="/admin/instructors" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
  Instructors
</NavLink>
<NavLink to="/admin/Enrollment" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
  Enrollment
</NavLink>
<NavLink to="/admin/departments" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
  Department
</NavLink>
<NavLink to="/admin/classrooms" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
  Classroom
</NavLink>
<NavLink to="/admin/schedule" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
  Schedule
</NavLink>


      </div>
    </nav>
  );
}