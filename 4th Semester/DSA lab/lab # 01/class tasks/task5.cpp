#include <iostream>
using namespace std;

int DigitSum(int n) {
    if (n < 10) // Base case: if n has only one digit
        return n;
    else
        return n % 10 + DigitSum(n / 10); // Extract last digit and recursively sum the rest
}

int main() {
    int num;
    cout << "Enter a nonnegative integer: ";
    cin >> num;
    cout << "Digit sum of " << num << " is: " << DigitSum(num) << endl;
    return 0;
}
