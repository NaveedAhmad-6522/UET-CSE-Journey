% Define parameters
omega1 = 0.5; % Frequency of x1
a_values = [0.5, 1.5]; % Values of 'a'
n = 0:10; % Range of 'n'

% Generate signals for each 'a'
for i = 1:length(a_values)
    a = a_values(i);
    
    % Generate signals
    x1 = 5 * exp(1i * omega1 * n); % x1(n)
    x2 = a * n; % x2(n)
    
    % Perform point-by-point multiplication
    y = x1 .* x2;
    
    % Plot real and imaginary parts
    figure;
    subplot(2,1,1);
    plot(n, real(y), 'b-o', 'LineWidth', 2);
    xlabel('n');
    ylabel('Real(y)');
    title(['Real Part of Product (a = ', num2str(a), ')']);
    grid on;
    
    subplot(2,1,2);
    plot(n, imag(y), 'r-o', 'LineWidth', 2);
    xlabel('n');
    ylabel('Imaginary(y)');
    title(['Imaginary Part of Product (a = ', num2str(a), ')']);
    grid on;
end
