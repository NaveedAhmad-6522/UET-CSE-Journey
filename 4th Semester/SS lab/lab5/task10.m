% Define parameters
A = 3;
pi_val = -0.4;
omega = 2 * pi * 1250;
t = linspace(0, 2/1250, 1000); % Time range covering 2 periods (1 period = 1/frequency)

% Generate signal
x = A * exp(1i * (pi_val * t + omega));

% Plot real and imaginary parts
figure;
subplot(2,1,1);
plot(t, real(x), 'b', 'LineWidth', 2);
xlabel('t');
ylabel('Real(x(t))');
title('Real Part of x(t)');
grid on;

subplot(2,1,2);
plot(t, imag(x), 'r', 'LineWidth', 2);
xlabel('t');
ylabel('Imaginary(x(t))');
title('Imaginary Part of x(t)');
grid on;
