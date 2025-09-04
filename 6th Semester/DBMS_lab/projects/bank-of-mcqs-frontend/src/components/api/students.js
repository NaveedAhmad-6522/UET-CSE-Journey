import axios from 'axios';
const API_URL = 'https://uetapi.bomseries.shop/api'; // ✅ Use 127.0.0.1 to match Laravel

export const getStudents = () => axios.get(`${API_URL}/students`);
export const addStudent = (data) => axios.post(`${API_URL}/students`, data);
export const updateStudent = (id, data) => axios.put(`${API_URL}/students/${id}`, data);
export const deleteStudent = (id) => axios.delete(`${API_URL}/students/${id}`);