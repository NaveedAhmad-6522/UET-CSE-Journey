% Original signal
n = 0:5;
x = [1, 2, 3, 4, 5, 6];

% Pad the signal with zeros
x_padded = [x, zeros(1, length(x))]; % Pad with zeros

% Plot original signal
subplot(3,1,1);
stem(n, x, 'black', 'LineWidth', 1.5);
xlabel('Sample Index (n)');
ylabel('Amplitude');
title('Original Signal');
grid on;

% Up-sample the padded signal by a factor of 2
n_upsampled = 0:0.5:length(x_padded)-0.5; % Adjusted length
x_upsampled = interp(x_padded, 2); % Up-sample by a factor of 2

% Plot up-sampled signal
subplot(3,1,2);
stem(n_upsampled, x_upsampled(1:length(n_upsampled)), 'b', 'LineWidth', 1.5);
xlabel('Sample Index (n)');
ylabel('Amplitude');
title('Up-sampled Signal (Factor of 2)');
grid on;

% Interpolation with linear interpolation method
n_interp = 0:0.1:length(x_padded)*2-1; % Adjusted length
x_interp = interp1(n_upsampled, x_upsampled, n_interp, 'linear'); % Interpolate

% Plot interpolated signal
subplot(3,1,3);
plot(n_interp, x_interp, 'p', 'LineWidth', 1.5);
xlabel('Sample Index (n)');
ylabel('Amplitude');
title('Interpolated Signal (Linear Interpolation)');
grid on;
