t=0:0.001:1;
f=10;
y = sin(2*pi*f*t);
for i = 1:6    
    y = y + sin(2*pi*f*i*t) ;
end

subplot(2,1,1)
plot(t,y)
title('Composite SIgnal');
xlabel('Time');
ylabel('Amplitude');
grid on;

x_f = fft(y);
x_fshift = fftshift(x_f);

w=-(length(y)-1)/2:(length(y) -1)/2;

subplot(2,1,2)
plot(w,abs(x_fshift))
title('Fourier Transform of Composite Signal');
xlabel('Frequency');
ylabel('Amplitude');
grid on;