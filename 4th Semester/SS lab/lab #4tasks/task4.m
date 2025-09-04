x = linspace(-10, 10, 100);
y1 = 2*x + 3;
y2 = 4*x + 3;
plot(x, y1, '-r', 'LineWidth', 2); % Plot y1 with a red solid line
hold on; % Keep the current plot
plot(x, y2, '--b', 'LineWidth', 2); % Plot y2 with a blue dashed line
xlabel('x');
ylabel('y');
title('Plot of y1 = 2x + 3 and y2 = 4x + 3');
legend('y1', 'y2');
grid on;
hold off; % Release the current plot