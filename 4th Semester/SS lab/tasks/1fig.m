% Define the x and y coordinates
x = [0, 1, 2, 3];
y = [1, 0.9013, 0.5, 0.353];

% Create the plot
figure; % Open a new figure window
plot(x, y, '-o'); % Plot the points and connect them with lines

% Add labels and title
xlabel('x');
ylabel('y');
title('Graph of Given Points');

% Add grid for better visualization
grid on;

% Display the plot
hold off;
