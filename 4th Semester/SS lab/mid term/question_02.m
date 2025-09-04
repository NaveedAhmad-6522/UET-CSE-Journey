registration_number = input('Enter registration number: ', 's');


numeric_portion = '';
for i = 1:length(registration_number)
    if isstrprop(registration_number(i), 'digit')
        numeric_portion = [numeric_portion, registration_number(i)];
    end
end


disp(['The numeric portion of the entered registration number is ', numeric_portion]);


part1 = str2double(numeric_portion(1:2));
part2 = str2double(numeric_portion(3:4));
part3 = str2double(numeric_portion(5:6));


a = @(x) part1 * x + part1;
b = @(x) part2 * x + part2;
c = @(x) part3 * x + part3;

x = linspace(-10, 10);


figure;
hold on;
plot(x, a(x), '-r', 'LineWidth', 2);
plot(x, b(x), '--g', 'LineWidth', 2); 
plot(x, c(x), ':b', 'LineWidth', 2); 


xlabel('x');
ylabel('y');
title('Curves a, b, and c');
legend('a', 'b', 'c');
grid on;
hold off;
