t=0:0.001:1;
f1=80;
f2=100;
y1 = 0.5 * sin(2*pi*f1*t);
y2 = 0.7 * sin(2*pi*f2*t);
y = y1 + y2;
figure(1)
subplot(2,1,1)
plot(t,y);
title('Noise Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;
x_f = fft(y);
x_fshift = fftshift(x_f);
subplot(2,1,2)
plot(w,abs(x_fshift))
title('Spectrum of Noise Signal');
xlabel('Frequency');
ylabel('Amplitude');
grid on;