% Define a proper low-pass filter
lpFilt = designfilt('lowpassfir', 'PassbandFrequency', 2, ...
    'StopbandFrequency', 5, 'PassbandRipple', 0.5, 'StopbandAttenuation', 60, ...
    'SampleRate', fs);
 
% Demodulate Lower Sideband Signal (LSB)
demod_lsb = lowerSidebandSignal .* cos(2 * pi * fc * t);  % Multiply with carrier
s1 = filtfilt(lpFilt, demod_lsb);  % Apply low-pass filter
 
% Scale demodulated signal to match original amplitude
s1 = s1 / max(abs(s1)) * max(abs(x));
 
% Demodulate Upper Sideband Signal (USB)
demod_usb = upperSidebandSignal .* cos(2 * pi * fc * t);  % Multiply with carrier
s2 = filtfilt(lpFilt, demod_usb);  % Apply low-pass filter
 
% Scale demodulated signal to match original amplitude
s2 = s2 / max(abs(s2)) * max(abs(x));
figure;
plot(t, x, 'k', t, s1, 'r:', t, s2, 'g-.');  % Plot original and demodulated signals
title('Comparison of Original and Demodulated Signals');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Original Signal', 'Demodulated LSB', 'Demodulated USB');
xlim([0.2, 3.5]);  % Adjust time range for better visualization
grid on;

