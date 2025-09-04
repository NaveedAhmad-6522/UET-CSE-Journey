t = 0:0.001:1; 
f1 = 80;      
f2 = 100;     
f = 10;        
y1 = 0.5 * sin(2*pi*f1*t);
y2 = 0.7 * sin(2*pi*f2*t);
y = y1 + y2;
x = zeros(size(t));
for i = 1:6    
    x = x + sin(2*pi*f*i*t);
end
figure(1);
subplot(2,2,1);
plot(t, y);
title('Noise');
xlabel('Time');
ylabel('Amplitude');
grid on;

subplot(2,2,3);
plot(t, x + y); 
title('Noise + Wanted Signal in Time Domain');
xlabel('Time');
ylabel('Amplitude');
grid on;

N = length(y);                  
Fs = 1 / (t(2) - t(1));        
f_axis = (-N/2:N/2-1) * (Fs / N); 

y_f = fft(y, N);                
y_fshift = fftshift(y_f);       

x_f = fft(x + y, N);            
x_fshift = fftshift(x_f);       

subplot(2,2,2);
plot(f_axis, abs(y_fshift));
title('Spectrum of Noise Signal');
xlabel('Frequency (Hz)');
ylabel('Amplitude');
grid on;

subplot(2,2,4);
plot(f_axis, abs(x_fshift));
title('Spectrum of Signal + Noise');
xlabel('Frequency (Hz)');
ylabel('Amplitude');
grid on;
