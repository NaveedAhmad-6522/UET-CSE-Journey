%Modulate signals
t = (0:1/fs:10)';  
x = sin(2 * pi * 1 * t);  % Modulating signal
carrier_cos = cos(2 * pi * fc * t);  % Cosine carrier
carrier_sin = sin(2 * pi * fc * t);  % Sine carrier
% Double-Sideband Modulation (DSB)
ydouble = x .* carrier_cos;
% Hilbert Transform for SSB (Single Sideband Modulation)
x_hilbert = imag(hilbert(x));  
% Lower Sideband (LSB)
lowerSidebandSignal = x .* carrier_cos - x_hilbert .* carrier_sin;
% Upper Sideband (USB)
upperSidebandSignal = x .* carrier_cos + x_hilbert .* carrier_sin;
 
figure;
subplot(3,1,1);
plot(t, ydouble);
title('Double-Sideband AM');
xlabel('Time (s)');
ylabel('Amplitude');
 
subplot(3,1,2);
plot(t, lowerSidebandSignal);
title('Lower Sideband Signal (LSB)');
xlabel('Time (s)');
ylabel('Amplitude');
 
subplot(3,1,3);
plot(t, upperSidebandSignal);
title('Upper Sideband Signal (USB)');
xlabel('Time (s)');
ylabel('Amplitude');

