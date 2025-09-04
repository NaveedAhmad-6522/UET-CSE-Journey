import axios from 'axios';

const API_URL= 'https://uetapi.bomseries.shop/api'; // ✅ Use 127.0.0.1 to match Laravel

export const getInstructors = () => axios.get(`${API_URL}/instructors`);
export const addInstructor = (data) => axios.post(`${API_URL}/instructors`, data);
export const updateInstructor = (id, data) => axios.put(`${API_URL}/instructors/${id}`, data);
export const deleteInstructor = (id) => axios.delete(`${API_URL}/instructors/${id}`);
export const getDepartments = () => axios.get(`${API_URL}/departments`);
