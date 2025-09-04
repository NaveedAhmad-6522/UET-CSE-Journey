% Generate a non-causal signal
x = [0, 0, 0, 0, 1, 1, 1, 1, 1, 0];

% Create a position vector
position = [0, 0, 0, 0, 1, 1, 1, 1, 1, 0];

% Ensure the signal and position vector have the same length
if length(x) ~= length(position)
    error('Signal and position vector must have the same length');
end

% Find the index of the first non-zero element in the position vector
first_nonzero_index = find(position, 1);

% Make the signal causal by shifting it to the right
y = circshift(x, first_nonzero_index - 1);

% Plot the original non-causal signal
subplot(2,1,1);
stem(x);
title('Original Non-Causal Signal');
xlabel('Time Index');
ylabel('Amplitude');

% Plot the resultant causal signal
subplot(2,1,2);
stem(y);
title('Resultant Causal Signal');
xlabel('Time Index');
ylabel('Amplitude');