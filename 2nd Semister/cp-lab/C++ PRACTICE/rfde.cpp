#include <iostream>

void addNumbers(int num1, int num2, int* result) {
    *result = num1 + num2;
}

int main() {
    int num1, num2, result;
    
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    
    addNumbers(num1, num2, result);
    
    std::cout << "The sum is: " << result << std::endl;
    
    return 0;
}

