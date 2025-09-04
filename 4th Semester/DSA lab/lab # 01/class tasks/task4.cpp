#include <iostream>
using namespace std;
/*Unlike many programming languages, C++ does not include a predefined operator that raises a number to 
a power. As a partial remedy for this deficiency, write a recursive implementation of a function   int 
RaiseIntToPower(int n, int k)
that calculates nk. The recursive insight that you need to solve this problem is the mathematical property that  
*/

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else if (exp < 0) {
        return static_cast<float>(1.0 / base) * power(base, exp + 1); // Corrected negative exponent calculation
    } else
        return base * power(base, exp - 1);
}

int main() {
    cout << "Enter base and exponent: ";
    int x, y;
    cin >> x >> y;
    cout << x << "^" << y << " = " << power(x, y) << endl;
    return 0;
}
