% Define the exponential signal
t = 0:0.01:2*pi; % Time vector
A = 3; % Amplitude
f = 2; % Frequency (in Hz)
phi = pi/4; % Phase (in radians)
x = A * exp(1i * (2 * pi * f * t + phi)); % Exponential signal

% Compute the complex conjugate
conj_x = conj(x);

% Plot real and imaginary parts
figure;
subplot(2,1,1);
plot(t, real(conj_x), 'b', t, imag(conj_x), 'r');
xlabel('Time');
ylabel('Amplitude');
title('Real and Imaginary Parts of Complex Conjugate');
legend('Real Part', 'Imaginary Part');
grid on;

% Plot magnitude and phase
subplot(2,1,2);
plot(t, abs(conj_x));
xlabel('Time');
ylabel('Magnitude');
title('Magnitude of Complex Conjugate');
grid on;
