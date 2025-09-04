% Define the range of n
n = -10:10;

% Initialize the signum sequence with zeros
signum_seq = zeros(size(n));

% Assign 1 to positive values of n, -1 to negative values, and leave 0 as it is
signum_seq(n > 0) = 1;
signum_seq(n < 0) = -1;

% Plot the signum sequence
stem(n, signum_seq, 'black', 'LineWidth', 1.5);
xlabel('n');
ylabel('Signum Sequence');
title('Plot of Signum Sequence');
grid on;
