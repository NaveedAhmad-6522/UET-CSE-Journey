// Write the C++ code that takes 5 numbers (a, b, c, d and e) from the user and display the 
//output according to the following equation.
 //a3 + b – d / b  divid by
//a (b + c (e + a) / b) - 5.
#include <iostream>
using namespace std;

int main() {
    float a, b, c, d, e, result;

    cout << "Enter value for a: ";
    cin >> a;

    cout << "Enter value for b: ";
    cin >> b;

    cout << "Enter value for c: ";
    cin >> c;

    cout << "Enter value for d: ";
    cin >> d;

    cout << "Enter value for e: ";
    cin >> e;

    result = (a*a*a + b - d / b) / (a * (b + c * (e + a) / b) - 5);

    cout << "Result: " << result << endl;

    return 0;
}

