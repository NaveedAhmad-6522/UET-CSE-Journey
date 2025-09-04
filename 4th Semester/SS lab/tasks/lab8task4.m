clc;
clear all;
close all;

impulseResponse = [3 -1 2 1];
inputSig = [2 4 6 4 2];
outPut = conv(impulseResponse, inputSig);
 
figure(1);
subplot(2, 1, 1);
stem(inputSig);
title('Discrete Filter Input x[n]'); 
xlabel('index, n');
ylabel('Value, x[n]');
 
subplot(2,1,2);
stem(outPut, 'r');
title('Discrete Filter Output y[n]');
xlabel('index, n');
ylabel('Value, y[n]');