% Define the signal
n = -10:10;
y = 5 * exp(1i * n * pi/4);

% Flip the signal
y_flipped = fliplr(y);

% Plot the original and flipped signals
subplot(2,1,1);
stem(n, real(y), 'b', 'LineWidth', 1.5);
hold on;
stem(n, imag(y), 'g', 'LineWidth', 1.5);
xlabel('n');
ylabel('Amplitude');
title('Original Signal');
legend('Real Part', 'Imaginary Part');
grid on;

subplot(2,1,2);
stem(n, real(y_flipped), 'b', 'LineWidth', 1.5);
hold on;
stem(n, imag(y_flipped), 'g', 'LineWidth', 1.5);
xlabel('n');
ylabel('Amplitude');
title('Flipped Signal');
legend('Real Part', 'Imaginary Part');
grid on;

% Adjust figure
suptitle('Original and Flipped Signals');
