clc; 
clear all;
close all;
fs=1;
t=-3:0.3:3; 
A=5; 
phase=pi/2; 
f=3;
x=A * cos(2*pi*f*t);
y=A * sin(2*pi*f*t + phase);
subplot(2,1,1)
plot(t,x)
title('Continuous-Time cos Wave: A cos(2*\pi*f*t)')
xlabel('Time')
ylabel('Amplitude') 
axis([t(1) t(end) -A A]) 
grid
subplot(2,1,2)
plot(t,y)
title('Continuous-Time Sine Wave: A sin(2*\pi*f*t + \phi)')
xlabel('Time ')
ylabel('Amplitude') 
axis([t(1) t(end) -A A]) 
grid on;