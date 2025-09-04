f0 = 3;
A = 5; 
t = -1:0.005:1; 

y_sine = A*cos(2*pi*f0*t + pi/2);

y_cosine = A*cos(2*pi*f0*t);

subplot(2, 1, 1);
plot(t, y_sine, 'b', 'LineWidth', 1.5);
xlabel('Time, sec');
ylabel('Amplitude');
title('Sine Wave with Phase Shift of +?/2');
grid on;

subplot(2, 1, 2);
plot(t, y_cosine, 'r', 'LineWidth', 1.5);
xlabel('Time, sec');
ylabel('Amplitude');
title('Cosine Wave with Phase Shift of 0');
grid on;

sgtitle('Comparison of Sine and Cosine Waves');
