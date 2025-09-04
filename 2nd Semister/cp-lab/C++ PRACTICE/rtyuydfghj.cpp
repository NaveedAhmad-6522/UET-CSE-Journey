#include <iostream>
#include <string>
using namespace std;

int percentage(int marks) {
    return static_cast<int>(marks / 100.0 * 100);
}

float GPA(int marks) {
    if (marks >= 90 && marks <= 100) {
        return 4.0;
    } else if (marks >= 80 && marks < 90) {
        return 3.7;
    } else if (marks >= 70 && marks < 80) {
        return 3.3;
    } else if (marks >= 60 && marks < 70) {
        return 3.0;
    } else if (marks >= 50 && marks < 60) {
        return 2.7;
    } else if (marks >= 40 && marks < 50) {
        return 2.3;
    } else {
        return 0.0;
    }
}

void caller(int marks, float (*ptrfun)(int)) {
    float result = (*ptrfun)(marks);
    cout << "Result: " << result << endl;
}

int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    char choice;
    cout << "Enter choice (g for GPA, p for percentage): ";
    cin >> choice;

    if (choice == 'g') {
        caller(marks, GPA);
    } else if (choice == 'p') {
        int percentageResult = percentage(marks);
        cout << "Percentage: " << percentageResult << "%" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

