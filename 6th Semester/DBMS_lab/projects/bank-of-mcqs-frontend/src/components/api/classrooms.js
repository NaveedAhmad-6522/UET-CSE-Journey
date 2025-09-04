// src/api/classrooms.js
import axios from 'axios';
const API_URL = 'https://uetapi.bomseries.shop/api'; // ✅ Use 127.0.0.1 to match Laravel

export const getClassrooms = () => axios.get(`${API_URL}/classrooms`);
export const addClassroom = (data) => axios.post(`${API_URL}/classrooms`, data);
export const updateClassroom = (id, data) => axios.put(`${API_URL}/classrooms/${id}`, data);
export const deleteClassroom = (id) => axios.delete(`${API_URL}/classrooms/${id}`);
