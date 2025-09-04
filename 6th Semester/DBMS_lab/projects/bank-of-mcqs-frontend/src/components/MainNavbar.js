// src/components/MainNavbar.js
import React from 'react';
import { NavLink } from 'react-router-dom';
import './css/Mnavbar.css' // Adjust if path is different


export default function MainNavbar() {
  return (
    <nav className="navbar">
      <div className="navbar-logo">Harvard Portal</div>
      <div className="navbar-links">
        <NavLink to="/" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
          Home
        </NavLink>
        <NavLink to="/admin-login" className={({ isActive }) => isActive ? 'nav-link active' : 'nav-link'}>
          Admin Login
        </NavLink>
      </div>
    </nav>
  );
}