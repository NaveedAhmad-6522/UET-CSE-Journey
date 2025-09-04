#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a, b;
        char op;

        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Enter an operation (+, -, *, /): ";
        cin >> op;

        switch (op) {
            case '+':
                cout << a + b;
                break;
            case '-':
                cout << a - b;
                break;
            case '*':
                cout << a * b;
                break;
            case '/':
                if (b != 0) {
                    float x = (a) / b;
                    cout << x;
                } else {
                    cout << "Error: Division by zero!";
                }
                break;
            default:
                cout << "Error: Invalid operation!";
        }

        cout << endl;
    }

    return 0;
}

