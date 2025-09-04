// src/api/courses.js
import axios from 'axios';
axios.defaults.withCredentials = true;
const API_URL = 'https://uetapi.bomseries.shop/api'; // ✅ Use 127.0.0.1 to match Laravel
export const getCourses = () => axios.get(`${API_URL}/courses`);
export const addCourse = (data) => axios.post(`${API_URL}/courses`, data);
export const updateCourse = (id, data) => axios.put(`${API_URL}/courses/${id}`, data);
export const deleteCourse = (id) => axios.delete(`${API_URL}/courses/${id}`);
export const getInstructors = () => axios.get(`${API_URL}/instructors`);
export const getDepartments = () => axios.get(`${API_URL}/departments`);