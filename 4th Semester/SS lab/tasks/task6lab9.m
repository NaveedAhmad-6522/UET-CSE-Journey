clc;
clear all;
close all;
N = 17; % Number of terms
t = 0:0.01:0.25;
ff = 25;
x1 = (-8/(pi^2)) * exp(1i*(2*pi*ff*t));
y = x1; % Initialize y with x1
for k = 3:2:N
    fh = ff*k;
    x = (-8/(pi^2*k^2)) * exp(1i*(2*pi*fh*t));
    y = y + x; % Accumulate the terms
end
plot(t, real(y), 'linewidth', 3);
title('Triangular Wave with N=17');
ylabel('Amplitude');
xlabel('Time');
grid;
