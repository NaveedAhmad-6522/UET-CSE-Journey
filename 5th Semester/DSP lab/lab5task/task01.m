fs = 100000; % Sampling frequency
t = 0:1/fs:0.02; % Time vector
L = length(t); % Signal length

% Message Signal
Am = 10; 
fm = 200;
ym = Am * cos(2 * pi * fm * t); 

% Carrier Signal
mi = 0.5; 
Ac = Am / mi; 
fc = 2000; 
yc = Ac * cos(2 * pi * fc * t); 

% Modulated Signal (DSB-FC)
y_mod = (1 + mi * ym / Am) .* yc; 

% Demodulated Signal (Envelope Detection)
y_env = sqrt(y_mod.^2 + [diff(y_mod), 0].^2); 

%% Time Domain Plots
figure;
sgtitle('Time Domain Signals'); % Overall title
subplot(4, 1, 1); plot(t, ym, 'b'); title('Message Signal'); xlabel('Time (s)'); ylabel('Amplitude'); grid on;
subplot(4, 1, 2); plot(t, yc, 'r'); title('Carrier Signal'); xlabel('Time (s)'); ylabel('Amplitude'); grid on;
subplot(4, 1, 3); plot(t, y_mod, 'm'); title('Modulated Signal'); xlabel('Time (s)'); ylabel('Amplitude'); grid on;
subplot(4, 1, 4); plot(t, y_env - mean(y_env), 'g'); title('Demodulated Signal'); xlabel('Time (s)'); ylabel('Amplitude'); grid on;

%% Frequency Domain Plots
figure;
sgtitle('Frequency Domain Signals'); % Overall title
f_shift = linspace(-fs/2, fs/2, L); % Frequency range for centered FFT

% Message Signal - Frequency Domain
Y = fftshift(fft(ym)); % Center the spectrum
subplot(4, 1, 1); plot(f_shift, abs(Y/L)); xlim([-300, 4000]); title('Message Signal'); xlabel('Frequency (Hz)'); ylabel('|Amplitude|'); grid on;

% Carrier Signal - Frequency Domain
Y = fftshift(fft(yc));
subplot(4, 1, 2); plot(f_shift, abs(Y/L)); xlim([-300, 4000]); title('Carrier Signal'); xlabel('Frequency (Hz)'); ylabel('|Amplitude|'); grid on;

% Modulated Signal - Frequency Domain
Y = fftshift(fft(y_mod));
subplot(4, 1, 3); plot(f_shift, abs(Y/L)); xlim([-300, 4000]); title('Modulated Signal'); xlabel('Frequency (Hz)'); ylabel('|Amplitude|'); grid on;

% Demodulated Signal - Frequency Domain
Y = fftshift(fft(y_env));
subplot(4, 1, 4); plot(f_shift, abs(Y/L)); xlim([-300, 4000]); title('Demodulated Signal'); xlabel('Frequency (Hz)'); ylabel('|Amplitude|'); grid on;  