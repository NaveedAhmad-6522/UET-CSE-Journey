% Define parameters
a_values = [0.7, 1.3]; % Values of 'a'
n = 0:10; % Range of 'n'

% Generate signals for each 'a'
for i = 1:length(a_values)
    a = a_values(i);
    
    % Discrete-time signal
    x_discrete = a * n;
    
    % Continuous-time signal (assuming a sampling period of 1)
    t_continuous = 0:0.01:10; % Time vector for continuous signal
    x_continuous = a * t_continuous;
    
    % Plot signals
    figure;
    hold on;
    plot(n, x_discrete, 'bo-', 'LineWidth', 2); % Discrete-time signal
    plot(t_continuous, x_continuous, 'r-', 'LineWidth', 2); % Continuous-time signal
    hold off;
    
    % Labeling and title
    xlabel('n or t');
    ylabel('x(n) or x(t)');
    title(['Real-Exponential Signal: a = ', num2str(a)]);
    legend('Discrete-time (x[n])', 'Continuous-time (x(t))');
    grid on;
end
