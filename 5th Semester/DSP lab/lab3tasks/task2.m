
Fs = 1000; 
T = 1/Fs; 
t = 0:T:0.25; 
x = sin(2*pi*50*t) + sin(2*pi*120*t); 
y = x + 2 * randn(size(t));  

figure;
plot(t, y);
title('Noisy Signal y');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
