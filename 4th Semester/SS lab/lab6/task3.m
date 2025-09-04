x_continuous = linspace(0, 2*pi, 1000);

x_discrete = 0:0.1:2*pi;

y_continuous = exp(-x_continuous) .* sin(8*x_continuous);

y_discrete = exp(-x_discrete) .* sin(8*x_discrete);

figure;

subplot(2, 1, 1);
plot(x_continuous, y_continuous, 'b', 'LineWidth', 1.5);
xlabel('Time (t)');
ylabel('Amplitude');
title('Continuous-time representation: e^{-x}sin(8x)');
grid on;

subplot(2, 1, 2);
stem(x_discrete, y_discrete, 'r', 'filled', 'LineWidth', 1.5);
xlabel('Time (n)');
ylabel('Amplitude');
title('Discrete-time representation: e^{-x}sin(8x)');
grid on;

sgtitle('Continuous-time and Discrete-time Representations');
