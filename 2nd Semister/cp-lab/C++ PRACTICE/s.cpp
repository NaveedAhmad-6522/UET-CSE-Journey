#include <iostream>
using namespace std;

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    } else if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    } else {
        double result = power(base, exponent / 2);
        result *= result;
        if (exponent % 2 == 1) {
            result *= base;
        }
        return result;
    }
}

int main() {
    double base;
    int exponent;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    cout << base << "^" << exponent << " = " << power(base, exponent) << endl;

    return 0;
}

