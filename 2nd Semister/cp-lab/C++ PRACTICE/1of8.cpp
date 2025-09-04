#include <iostream>

void addValues(int a, int b, int* resultPtr) {
    *resultPtr = a + b;
}

int main() {
    int num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int* sumPtr#include <iostream>

void addValues(int a, int b, int* resultPtr) {
    *resultPtr = a + b;
}

int main() {
    int num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int* sumPtr = new int; // Dynamically allocate memory for the result

    addValues(num1, num2, sumPtr);

    std::cout << "Sum: " << *sumPtr << std::endl;

    delete sumPtr; // Free the dynamically allocated memory

    return 0;
}
  addValues(num1, num2, sumPtr);

    std::cout << "Sum: " << *sumPtr << std::endl;

    delete sumPtr; // Free the dynamically allocated memory

    return 0;
}

