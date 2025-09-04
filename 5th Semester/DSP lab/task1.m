time = 0 : 0.001 : 1;
frequency_a = 10;
frequency_b = 20;
frequency_c = 30;
frequency_d = 40;
frequency_e = 50;
frequency_f = 60;

signal_a = sin(2*pi*frequency_a*time);
subplot(3, 2, 1)
plot(time, signal_a);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 10 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

signal_b = sin(2*pi*frequency_b*time);
subplot(3, 2, 2)
plot(time, signal_b);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 20 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

signal_c = sin(2*pi*frequency_c*time);
subplot(3, 2, 3)
plot(time, signal_c);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 30 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;


signal_d = sin(2*pi*frequency_d*time);
subplot(3, 2, 4)
plot(time, signal_d);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 40 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

signal_e = sin(2*pi*frequency_e*time);
subplot(3, 2, 5)
plot(time, signal_e);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 50 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;


signal_f = sin(2*pi*frequency_f*time);
subplot(3, 2, 6)
plot(time, signal_f);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 60 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;
