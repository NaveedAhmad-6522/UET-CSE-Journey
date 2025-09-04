fs = 100;  
fc = 10;   
t = (0:1/fs:100)';  
x = sin(2 * pi * 1 * t);       % Modulating signal
yc = sin(2 * pi * fc * t);     % Carrier signal
figure;
plot(t, x, 'r', t, yc, 'b--'); 
xlabel('Time (s)');
ylabel('Amplitude');
legend('Original Signal', 'Carrier Signal');
title('Figure 1: Modulating and Carrier Signal');
xlim([0.2, 2]);               
ylim([-1, 1]);               
xticks(0.2:0.2:2);           
yticks(-1:0.2:1);             
grid on;
