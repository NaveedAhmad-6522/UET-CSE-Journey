x = linspace(-1, 1, 1000); 
figure;

for n = 1:8
    y = sin(n*pi*x);

    plot(x, y);
    
    hold on;
end

xlabel('x');
ylabel('sin(n\pi x)');
title('Graph of sin(n\pi x) for n = 1 to 8');
legend('show');
