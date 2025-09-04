#include <iostream>

// Function template
template<typename T>
T processData(T a, T b) {
    return a + b; // Change this line with your desired logic
}

int main() {
    // Prompt for data type
    std::cout << "Enter the data type (float, int, double): ";
    std::string dataType;
    std::cin >> dataType;

    // Prompt for numbers
    std::cout << "Enter the first number: ";
    if (dataType == "float") {
        float num1, num2;
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;
        std::cout << "Result: " << processData(num1, num2) << std::endl;
    } else if (dataType == "int") {
        int num1, num2;
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;
        std::cout << "Result: " << processData(num1, num2) << std::endl;
    } else if (dataType == "double") {
        double num1, num2;
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;
        std::cout << "Result: " << processData(num1, num2) << std::endl;
    } else {
        std::cout << "Invalid data type entered." << std::endl;
    }

    return 0;
}

