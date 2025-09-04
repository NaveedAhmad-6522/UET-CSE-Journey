#include <iostream>
#include <string>
using namespace std;

void printNameRegID(string name, double regID, int n) {
    // Base case: stop recursion when n is 0
    if (n == 0) {
        return;
    }
    
    // Print the name and registration ID
    cout << name << " " << regID << endl;
    
    // Recursively call printNameRegID with n-1
    printNameRegID(name, regID, n-1);
}

int main() {
    string name;
    double regID;
    
    // Get the user's name and registration ID
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your registration ID: ";
    cin >> regID;
    
    // Print the name and registration ID 10 times using recursion
    printNameRegID(name, regID, 10);
    
    return 0;
}

