fs = 1000; 
t = 0:1/fs:1; 
signal = sin(2*pi*50*t); 
noise = 0.5 * randn(size(t)); 
y = signal + noise; 

Y = fft(y, 251); 
Pyy = (Y .* conj(Y)) / 251; 
f = (1000/251) * (0:127); 

figure;
plot(f, abs(Pyy(1:128))); 
title('Power Spectral Density');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (Magnitude)');
xlim([0 fs/2]); 
grid on;
