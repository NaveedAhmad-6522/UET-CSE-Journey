//Write a program that takes a number as input, checks it if it is between 1 and 10
//and if it is in valid range your program should output a line containing that number of 
//adjacent asterisks. On invalid input number, the program should end.
//For example, if your program input is 7, it should print *******

#include <iostream>

using namespace std;

int main() {
    int num;
    
    cout << "Enter a number between 1 and 10: ";
    cin >> num;
    
    if (num < 1 || num > 10) {
        cout << "Invalid input. Exiting program." << endl;
        return 0;
    }
    
    for (int i = 0; i < num; i++) {
        cout << "*";
    }
    
    cout << endl;
    
    return 0;
}

