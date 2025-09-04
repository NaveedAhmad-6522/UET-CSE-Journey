% User-defined function for amplitude scaling
function scaled_signal = scale_signal(signal, beta)
    scaled_signal = signal * beta;
end

% Main program

% Getting input from the user
signal = input('Enter the signal to be scaled: ');  % Assuming the signal is entered as an array
beta = input('Enter the scaling factor (beta): ');  % Read input as numerical value

% Scaling the signal using the user-defined function
scaled_output = scale_signal(signal, beta);

disp('Scaled output:');
disp(scaled_output);
