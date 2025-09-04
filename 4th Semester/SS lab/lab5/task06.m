% Define the range of n
n = -10:10;

% Generate the complex-valued signal
y = exp(0.25j * pi * n);

% Plot magnitude, phase, real part, and imaginary part
figure;

% Magnitude plot
subplot(2,2,1);
plot(n, abs(y));
xlabel('n');
ylabel('|y(n)|');
title('Magnitude');
grid on;

% Phase plot
subplot(2,2,2);
plot(n, angle(y));
xlabel('n');
ylabel('Phase (radians)');
title('Phase');
grid on;

% Real part plot
subplot(2,2,3);
plot(n, real(y));
xlabel('n');
ylabel('Real(y(n))');
title('Real Part');
grid on;

% Imaginary part plot
subplot(2,2,4);
plot(n, imag(y));
xlabel('n');
ylabel('Imaginary(y(n))');
title('Imaginary Part');
grid on;
