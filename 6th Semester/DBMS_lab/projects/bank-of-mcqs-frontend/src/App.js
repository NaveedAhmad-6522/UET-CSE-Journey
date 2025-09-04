import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

import MainNavbar from './components/MainNavbar';
import AdminLayout from './components/pages/AdminLayout';

// Public Pages
import AvailableCoursesPage from './components/pages/AvailableCourses';
import IndexPage from './components/pages/IndexPage';
import AdminLoginPage from './components/pages/Login';
import ApplyPage from './components/pages/ApplyPage';
// Admin Pages
import StudentsPage from './components/pages/StudentsPage';
import CoursesPage from './components/pages/CoursesPage';
import InstructorsPage from './components/pages/InstructorsPage';
import EnrollmentPage from './components/pages/EnrollmentPage';
import DepartmentsPage from './components/pages/DepartmentPage';
import ClassroomPage from './components/pages/ClassroomPage';
import SchedulePage from './components/pages/SchedulePage';

function App() {
  return (
    <Router>
      
      <Routes>
  {/* ✅ Public Home Page */}
  <Route
    path="/"
    element={
      <>
        <MainNavbar />
        <IndexPage />
      </>
    }
  />

  {/* ✅ Apply Page */}
  <Route
    path="/apply"
    element={
      <>
        <MainNavbar />
        <ApplyPage />
      </>
    }
  />

  {/* ✅ Available Courses */}
<Route
  path="/courses"
  element={
    <>
      <MainNavbar />
      <AvailableCoursesPage />
    </>
  }
/>

  {/* ✅ Admin Login */}
  <Route
    path="/admin-login"
    element={
      <>
        <MainNavbar />
        <AdminLoginPage />
      </>
    }
  />


        {/* ✅ Admin Pages with Nested Routes */}
        <Route path="/admin" element={<AdminLayout />}>
          <Route path="students" element={<StudentsPage />} />
          <Route path="courses" element={<CoursesPage />} />
          <Route path="instructors" element={<InstructorsPage />} />
          <Route path="enrollment" element={<EnrollmentPage />} />
          <Route path="departments" element={<DepartmentsPage />} />
          <Route path="classrooms" element={<ClassroomPage />} />
          <Route path="schedule" element={<SchedulePage />} />
        </Route>
      </Routes>
    </Router>
  );
}


export default App;