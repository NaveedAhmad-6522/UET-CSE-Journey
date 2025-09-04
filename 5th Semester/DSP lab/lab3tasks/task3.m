Fs = 1000;             
T = 1/Fs;              
t = 0:T:0.25;          
x = sin(2*pi*50*t) + sin(2*pi*120*t);  
y = x + 2 * randn(size(t));  
Y = fft(y, 251);          
f = Fs*(0:(251/2))/251;       
Y_mag = abs(Y/251);         
Y_mag = Y_mag(1:126);       

figure;
plot(f, Y_mag(1:126));
title('Magnitude of DFT of Noisy Signal y');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;
