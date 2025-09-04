% Define the range of n
n = -5:5;

% Compute the unit impulse function
delta = zeros(size(n));
delta(n == 0) = 1;

% Compute the unit step function
u = zeros(size(n));
u(n >= 0) = 1;

% Compute the expression u[n] - u[n - 1]
expr_result = u - [0, u(1:end-1)];

% Plot the results
subplot(3,1,1);
stem(n, delta, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('\delta[n]');
title('Unit Impulse Function');

subplot(3,1,2);
stem(n, u, 'r', 'LineWidth', 1.5);
xlabel('n');
ylabel('u[n]');
title('Unit Step Function');

subplot(3,1,3);
stem(n, expr_result, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('u[n] - u[n - 1]');
title('Expression Result');

% Add a super title to the figure
suptitle('Proof of \delta[n] = u[n] - u[n - 1]');
