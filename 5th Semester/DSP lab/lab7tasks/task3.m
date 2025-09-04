% Spectrum Analysis Using FFT
n = length(t);  % Number of samples
f = (-n/2:n/2-1) * (fs/n);  % Frequency vector
% Compute FFT for each signal
fft_double = fftshift(abs(fft(ydouble))/n);
fft_lsb = fftshift(abs(fft(lowerSidebandSignal))/n);
fft_usb = fftshift(abs(fft(upperSidebandSignal))/n);
 
% Plot Spectrum
figure;
subplot(3,1,1);
plot(f, fft_double);
title('Spectrum of Double-Sideband Signal');
xlabel('Frequency (Hz)');
ylabel('Amplitude');
 
subplot(3,1,2);
plot(f, fft_lsb);
title('Spectrum of Upper Sideband Signal');
xlabel('Frequency (Hz)');
ylabel('Amplitude');
 
subplot(3,1,3);
plot(f, fft_usb);
title('Spectrum of Lower Sideband Signal');
xlabel('Frequency (Hz)');
ylabel('Amplitude');

