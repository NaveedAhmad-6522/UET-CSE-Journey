clc;
clear all;
close all;

sig1 = [3 1 1];
sig2 = [4 2 1];
sig3 = [3 2 1 2 3];
 
lhs = conv(conv(sig1, sig2), sig3)
rhs =  conv(sig1, conv(sig2, sig3))
 
figure(1);
subplot(2, 1, 1);
stem(lhs);
title('(x1[n]*x2[n])*x3[n]'); 
xlabel('index, n');
ylabel('Value, left hand side');
 
subplot(2,1,2);
stem(rhs, 'r');
title('x1[n]*(x2[n]*x3[n])');
xlabel('index, n');
ylabel('Value, right hand side');