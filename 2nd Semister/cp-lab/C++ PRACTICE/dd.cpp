#include <iostream>
using namespace std;

void addNumbers(int* ptr, int num1, int num2) {
    *ptr = num1 + num2;
    
}

int main() {
    int num1, num2, sum;
    int* ptr;

    // Input values from the user
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Assign address of sum variable to pointer
    //ptr = &sum;

    // Call the function to calculate the sum using the pointer
    addNumbers(ptr, num1, num2);

    // Print the sum
    cout << "Sum: " << *ptr << endl;

    return 0;
}

