% Original signal
t = 0:0.01:5;  % Time vector (assuming sampling every 0.01 seconds)
x = sin(2*pi*t);  % Original signal, for example

% Delay the signal by 1 second
delay = 1;  % Delay in seconds
Fs = 1/(t(2)-t(1));  % Sampling frequency
num_samples_delay = round(delay * Fs);  % Number of samples to delay
delayed_x = [zeros(1, num_samples_delay), x(1:end-num_samples_delay)];  % Delayed signal

% Plot both original and delayed signals
plot(t, x, 'black', 'LineWidth', 2);  % Original signal
hold on;
plot(t, delayed_x, 'y--', 'LineWidth', 2);  % Delayed signal
xlabel('Time (s)');
ylabel('Amplitude');
title('Original and Delayed Signals');
legend('Original Signal', 'Delayed Signal');
grid on;
