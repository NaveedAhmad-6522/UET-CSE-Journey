% Define parameters
A = 2; % Amplitude
f = 1; % Frequency (Hz)
phi = pi/4; % Phase (radians)
t = linspace(0, 2*pi, 1000); % Time vector

% Original sinusoid
x_original = A * sin(2*pi*f*t + phi);

% Scaled sinusoid
A_scaled = 2 * A; % Scale the amplitude by a factor of 2
x_scaled = A_scaled * sin(2*pi*f*t + phi);

% Plot the original and scaled sinusoids
plot(t, x_original, 'black', 'LineWidth', 1.5);
hold on;
plot(t, x_scaled, 'g', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Amplitude');
title('Comparison of Original and Scaled Sinusoids');
legend('Original', 'Scaled');
grid on;
