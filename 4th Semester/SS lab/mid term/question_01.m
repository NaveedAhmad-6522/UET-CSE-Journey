registration_number = input('Enter registration number: ', 's');

numeric_portion = '';
for i = 1:length(registration_number)
    if isstrprop(registration_number(i), 'digit')
        numeric_portion = [numeric_portion, registration_number(i)];labS
    end
end

disp(['The numeric portion of the entered registration number is ', numeric_portion]);
