/*Create a string array of size 2, in the first element enter your name and in the second 
element enter your registration number, using a pointer, now pass the array address to 
function called display(), which has a string pointer as a parameter, the function will
display both elements of the array.*/
#include <iostream>
using namespace std;
void display(string* arrPtr) {
    cout << "Name: " << arrPtr[0] << endl;
    cout << "Registration Number: " << arrPtr[1] << endl;
}
int main() {
    string arr[2];  // String array of size 2
    // Input values into the array
    cout << "Enter your name: ";
    getline(cin, arr[0]);
    cout << "Enter your registration number: ";
    getline(cin, arr[1]);
    // Pass array address to the display() function
    display(arr);
    return 0;
}

