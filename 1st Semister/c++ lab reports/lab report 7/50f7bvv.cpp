#include <iostream>
using namespace std;

void grade();
float grade(int marks);
char grade(float percentage);

void grade() {
    int marks;
    cin >> marks;
    float percentage = grade(marks);
    char gradeobt = grade(percentage);
    cout << "Your grade is " << gradeobt << endl;
}

float grade(int marks) {
    float percentage = (marks) / 150 * 100;
    return percentage;
}

char grade(float percentage) {
    char gradeobt;
    if (percentage >= 90) {
        return 'A';
    } else if (percentage >= 80) {
        return 'B';
    } else if (percentage >= 70) {
        return 'C';
    } else if (percentage >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    grade();
    return 0;
}

