import React from 'react';
import { Outlet } from 'react-router-dom';
import Navbar from '../Navbar';      // ✅ Admin navbar
import Footer from '../Footer';

export default function AdminLayout() {
  return (
    <>
      <Navbar />
      <main className="container" style={{ minHeight: '80vh', padding: '2rem 0' }}>
        <Outlet /> {/* ✅ Renders nested admin routes */}
      </main>
      <Footer />
    </>
  );
}