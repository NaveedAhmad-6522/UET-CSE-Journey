// src/api/enrollments.js
import axios from 'axios';
const API_URL = 'https://uetapi.bomseries.shop/api'; // ✅ Use 127.0.0.1 to match Laravel

export const getEnrollments = () => axios.get(`${API_URL}/enrollments`);
export const addEnrollment = (data) => axios.post(`${API_URL}/enrollments`, data);
export const deleteEnrollment = (id) => axios.delete(`${API_URL}/enrollments/${id}`);

// Optional: Fetch by student/course if you want later
// export const getEnrollmentsByStudent = (studentId) => axios.get(`${API_URL}/students/${studentId}/enrollments`);