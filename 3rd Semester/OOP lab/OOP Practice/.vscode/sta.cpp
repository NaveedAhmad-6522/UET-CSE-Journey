#include <iostream>
#include <cstring>

class Employee {
private:
    static int totalEmployees;
    int employeeId;
    char name[50];
    char designation[50];

public:
    // Constructor to initialize employee data
    Employee(int id, const char* empName, const char* empDesignation) : employeeId(id) {
        strncpy(name, empName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null-terminated
        strncpy(designation, empDesignation, sizeof(designation) - 1);
        designation[sizeof(designation) - 1] = '\0'; // Ensure null-terminated
        totalEmployees++; // Increment totalEmployees when a new employee is created
    }

    // Destructor to decrement totalEmployees when an employee is deleted
    ~Employee() {
        totalEmployees--;
    }

    // Function to display employee information
    void displayEmployeeInfo() const {
        std::cout << "Employee ID: " << employeeId << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Designation: " << designation << std::endl;
    }

    // Function to update employee records
    void updateEmployeeInfo(const char* newName, const char* newDesignation) {
        strncpy(name, newName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null-terminated
        strncpy(designation, newDesignation, sizeof(designation) - 1);
        designation[sizeof(designation) - 1] = '\0'; // Ensure null-terminated
    }

    // Static function to display total number of employees
    static void displayTotalEmployees() {
        std::cout << "Total Employees: " << totalEmployees << std::endl;
    }
};

// Initialize static member variable
int Employee::totalEmployees = 0;

int main() {
    // Creating employee objects
    Employee emp1(1, "John Doe", "Software Engineer");
    Employee emp2(2, "Jane Smith", "Project Manager");

    // Displaying employee information
    std::cout << "Employee Information:" << std::endl;
    emp1.displayEmployeeInfo();
    emp2.displayEmployeeInfo();

    // Display total number of employees
    Employee::displayTotalEmployees();

    // Update employee records
    emp1.updateEmployeeInfo("John Doe Jr.", "Senior Software Engineer");

    // Display updated employee information
    std::cout << "\nUpdated Employee Information:" << std::endl;
    emp1.displayEmployeeInfo();
    emp2.displayEmployeeInfo();

    return 0;
}
