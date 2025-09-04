% Parameters
time = 0 : 0.001 : 1; % Time vector
frequencies = [10, 20, 30, 40, 50, 60]; % Signal frequencies
num_signals = length(frequencies); % Number of signals
Fs = 1000; % Sampling frequency (Hz)
L = length(time); % Number of samples

% Initialize composite signal
composite_signal = zeros(size(time)); 

figure; % Create a new figure for Figures 1 and 2

% Generate and plot individual signals
for i = 1:num_signals
    % Generate sinusoidal signal
    signal = sin(2 * pi * frequencies(i) * time);
    
    % Add to composite signal
    composite_signal = composite_signal + signal;
    
    % Plot individual signals (Figure 1)
    subplot(3, 2, i);
    plot(time, signal);
    xlabel('Time (s)');
    ylabel('Amplitude');
    title(['Sinusoidal Signal of ', num2str(frequencies(i)), ' Hz']);
    axis([0, 1, -1.5, 1.5]);
    grid on;
end

% Plot composite signal in a new figure (Figure 2)
figure;

% Time-domain representation of composite signal
subplot(2, 1, 1);
plot(time, composite_signal, 'b');
xlabel('Time (s)');
ylabel('Amplitude');
title('Composite Signal (Time-Domain)');
axis([0, 1, -5, 5]); % Adjust axis for composite signal
grid on;

% Frequency-domain representation of composite signal
fft_composite = fft(composite_signal); % FFT of composite signal
P2 = abs(fft_composite / L); % Two-sided spectrum
P1 = P2(1:L/2+1); % Single-sided spectrum
P1(2:end-1) = 2 * P1(2:end-1);
frequencies_fft = Fs * (0:(L/2)) / L; % Frequency vector

subplot(2, 1, 2);
plot(frequencies_fft, P1, 'r');
xlabel('Frequency (Hz)');
ylabel('|P1(f)|');
title('Composite Signal (Frequency-Domain)');
grid on;
