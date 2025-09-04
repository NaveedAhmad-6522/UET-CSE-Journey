% Define the signal
n = 0:4;
x = [2, 5, 8, 4, 3];

% Flip the signal
x_flipped = fliplr(x);

% Plot the original and flipped signals
subplot(2,1,1);
stem(n, x, 'black', 'LineWidth', 1.5);
xlabel('n');
ylabel('Amplitude');
title('Original Signal');
grid on;

subplot(2,1,2);
stem(n, x_flipped, 'b', 'LineWidth', 1.5);
xlabel('n');
ylabel('Amplitude');
title('Flipped Signal');
grid on;

% Adjust figure
suptitle('Original and Flipped Signals');
