fs = 1000; 
t = 0:1/fs:1; 
signal = sin(2*pi*50*t) + sin(2*pi*120*t); 
noise = 0.5 * randn(size(t)); 
y = signal + noise; 

Y = fft(y, 251); 
Pyy = (Y .* conj(Y)) / 251; 
f = (fs/251) * (0:125); 

figure;
plot(f(1:50), Pyy(1:50)); 
title('Zoomed In Power Spectral Density up to 200 Hz');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (Magnitude)');
xlim([0 200]);
grid on;
