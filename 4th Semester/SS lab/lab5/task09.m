% Define range of n
n = -10:10;

% Values of 'a'
a_values = [0.5, 2]; % Choose values of 'a'

% Generate signals for each 'a'
for i = 1:length(a_values)
    a = a_values(i);
    
    % Generate signal
    x = a * abs(n);
    
    % Plot the signal
    subplot(length(a_values), 1, i);
    stem(n, x, 'b', 'LineWidth', 2);
    xlabel('n');
    ylabel('x(n)');
    if a < 1
        title(['Discrete Signal for 0 < a < 1 (a = ', num2str(a), ')']);
    else
        title(['Discrete Signal for a > 1 (a = ', num2str(a), ')']);
    end
    grid on;
end
