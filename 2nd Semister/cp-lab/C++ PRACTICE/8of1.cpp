#include <iostream>

void addValues(int a, int b, int* result) {
     *result = a + b;
}

int main() {
    int num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int sum;
    int* result ;
    addValues(num1, num2, result);

    std::cout << "Sum: " << *result << std::endl;

    return 0;
}

