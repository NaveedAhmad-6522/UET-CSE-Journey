clc
clear all;
close all;

time = 0 : 0.01 : 10;
fundamentalFreq = 100;

sig = ((4/pi)*sin(2*pi*fundamentalFreq*time))/time;

for k = 1 : 2 : 100;
    harmonicFreq = k * fundamentalFreq;
    x = ((4/(k*pi))*sin(2*pi*harmonicFreq*time));
    sig = sig+x;
end

plot(time, sig, 'k', 'linewidth', 1.5);
xlabel('time, t');
ylabel('Amplitude, A');