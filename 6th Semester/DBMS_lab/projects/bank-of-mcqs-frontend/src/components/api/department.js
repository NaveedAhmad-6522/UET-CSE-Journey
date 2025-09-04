import axios from 'axios';

const API_URL= 'https://uetapi.bomseries.shop/api'; // Change to your backend API URL

// Course APIs
export const getCourses = () => axios.get(`${API_URL}/courses`);
export const addCourse = (data) => axios.post(`${API_URL}/courses`, data);
export const updateCourse = (id, data) => axios.put(`${API_URL}/courses/${id}`, data);
export const deleteCourse = (id) => axios.delete(`${API_URL}/courses/${id}`);

// Instructor APIs
export const getInstructors = () => axios.get(`${API_URL}/instructors`);

// Department APIs
export const getDepartments = () => axios.get(`${API_URL}/departments`);
export const addDepartment = (data) => axios.post(`${API_URL}/departments`, data);
export const updateDepartment = (id, data) => axios.put(`${API_URL}/departments/${id}`, data);
export const deleteDepartment = (id) => axios.delete(`${API_URL}/departments/${id}`);