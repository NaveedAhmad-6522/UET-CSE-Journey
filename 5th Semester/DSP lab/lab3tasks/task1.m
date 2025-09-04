% Spectral_Analysis.m

clear;
close all;
clc;

Fs = 1000;           
T = 1/Fs;            
t = 0:T:0.25;        
N = length(t);       

x = sin(2*pi*50*t) + sin(2*pi*120*t);
x = x + 0.5*randn(size(t));

figure;
plot(t, x);
title('Time-Domain Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

X = fft(x);                
X_mag = abs(X/N);          
frequencies = Fs*(0:(N/2))/N;   

PSD = (1/(Fs*N)) * abs(X(1:N/2+1)).^2;    
PSD(2:end-1) = 2*PSD(2:end-1);            

figure;
plot(frequencies, PSD);
title('Power Spectral Density of the Signal');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
grid on;

disp('Spectral Analysis complete. The Power Spectral Density (PSD) plot shows energy distribution over frequencies.');
