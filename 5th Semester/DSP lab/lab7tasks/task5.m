%Power Spectral Density using periodogram
[pxx, f_psd] = periodogram(x, rectwin(length(x)), length(x), fs, 'power');
 
% Plot PSD
figure;
plot(f_psd, 10*log10(pxx));  % Convert power to dB scale
title('Power Spectral Density');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
grid on;

