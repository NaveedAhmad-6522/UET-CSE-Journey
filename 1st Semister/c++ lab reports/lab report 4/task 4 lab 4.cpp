#include <iostream>
using namespace std;

int main() {
    int num1, num2, sum_of_evens = 0;
    
    // take inputs from the user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    // ensure that num1 is smaller than num2
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    // iterate over the range of numbers between num1 and num2
    for (int num = num1; num <= num2; num++) {
        // check if the number is even
        if (num % 2 == 0) {
            // add the even number to the sum
            sum_of_evens += num;
        }
    }
    
    // display the sum of even numbers
    cout << "The sum of even numbers between " << num1 << " and " << num2 << " is " << sum_of_evens << endl;
    
    return 0;
}

