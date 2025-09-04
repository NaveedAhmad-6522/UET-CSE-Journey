#include <iostream>

double percentage(int marks) {
    return (static_cast<double>(marks) / 100) * 100;
}

double GPA(int marks) {
    if (marks >= 90 && marks <= 100) {
        return 4.0;
    } else if (marks >= 80 && marks < 90) {
        return 3.0;
    } else if (marks >= 70 && marks < 80) {
        return 2.0;
    } else if (marks >= 60 && marks < 70) {
        return 1.0;
    } else {
        return 0.0;
    }
}

void caller(int marks, double (*func)(int)) {
    double result = func(marks);
    std::cout << "Result: " << result << std::endl;
}

int main() {
    int marks;
    int choice;

    std::cout << "Enter marks: ";
    std::cin >> marks;

    std::cout << "What do you want to find out?" << std::endl;
    std::cout << "1. Percentage" << std::endl;
    std::cout << "2. GPA" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        caller(marks, percentage);
    } else if (choice == 2) {
        caller(marks, GPA);
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }

    return 0;
}

