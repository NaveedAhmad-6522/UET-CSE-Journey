#include <iostream>
using namespace std;

double power(double base, int exponent) {
    // Base case: Any number raised to the power of 0 is 1
    if (exponent == 0) {
        return 1.0;
    }

    // Recursive case: Multiply the base by the power of (exponent - 1)
    return base * power(base, exponent - 1);
}

int main() {
    double base;
    int exponent;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << "Result: " << result << endl;

    return 0;
}

