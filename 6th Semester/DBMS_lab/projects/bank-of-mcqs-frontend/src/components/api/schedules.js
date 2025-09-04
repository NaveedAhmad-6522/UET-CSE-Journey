// src/api/schedules.js
import axios from 'axios';

const API_URL = 'https://uetapi.bomseries.shop/api'; // ✅ Use 127.0.0.1 to match Laravel

export const getSchedules = () => axios.get(`${API_URL}/schedules`);
export const addSchedule = (data) => axios.post(`${API_URL}/schedules`, data);
export const updateSchedule = (id, data) => axios.put(`${API_URL}/schedules/${id}`, data);
export const deleteSchedule = (id) => axios.delete(`${API_URL}/schedules/${id}`);
export const deleteInstructor = (id) => axios.delete(`${API_URL}/instructors/${id}`);