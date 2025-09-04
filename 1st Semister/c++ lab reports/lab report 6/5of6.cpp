#include <iostream>
#include <cmath>

using namespace std;

double deter(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    return d;
}

void roots(double a, double b, double c) {
    double d = deter(a, b, c);

    if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);
        cout << "Roots are real and different" << endl;
        cout << "Root 1: " << r1 << endl;
        cout << "Root 2: " << r2 << endl;
    } else if (d == 0) {
        double r = -b / (2 * a);
        cout << "Roots are real and equal" << endl;
        cout << "Root 1: " << r << endl;
        cout << "Root 2: " << r << endl;
    } else {
        double real_root = -b / (2 * a);
        double img_root = sqrt(-d) / (2 * a);
        cout << "Roots are imaginary" << endl;
        cout << "Real root: " << real_root << endl;
        cout << "Imaginary root: " << img_root << "i" << endl;
    }
}

int main() {
    double a, b, c;

    cout << "Enter coefficients of quadratic equation (ax^2 + bx + c): " << endl;
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Invalid input: a cannot be zero" << endl;
        return 0;
    }

    roots(a, b, c);

    return 0;
}

