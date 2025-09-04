% Define the coefficients and their corresponding indices
C = [22/7, 44/21, 22/21, 1, 22/21, 44/21, 22/7];
indices = -3:3;

% Plot the spectrum
figure;
stem(indices, C, 'filled');
grid on;

% Set the axis limits
xlim([-4 4]);
ylim([0 4]);

% Label the axes
xlabel('k');
ylabel('|C_k|');

% Add title
title('Spectrum');

% Adding labels for the stem points
for i = 1:length(indices)
    text(indices(i), C(i) + 0.1, ['C_', num2str(indices(i))], 'HorizontalAlignment', 'center');
end
