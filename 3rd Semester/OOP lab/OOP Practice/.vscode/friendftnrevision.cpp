#include <iostream>
#include <cstring> // For dynamic memory allocation with char*

class Employee {
private:
    char* name;
    char* department;
    double salary;
    double yearsOfService;

public:
    // Parameterless constructor
    Employee() : name(nullptr), department(nullptr), salary(0.0), yearsOfService(0.0) {}

    // 4-argument parameterized constructor with dynamic allocation
    Employee(const char* empName, const char* empDept, double empSalary, double empYears)
        : salary(empSalary), yearsOfService(empYears) {
        
        // Dynamic allocation for name
        name = new char[strlen(empName) + 1];
        strcpy(name, empName);

        // Dynamic allocation for department
        department = new char[strlen(empDept) + 1];
        strcpy(department, empDept);
    }

    // Copy constructor for deep copy
    Employee(const Employee& other)
        : salary(other.salary), yearsOfService(other.yearsOfService) {
        
        // Dynamic allocation for name
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        // Dynamic allocation for department
        department = new char[strlen(other.department) + 1];
        strcpy(department, other.department);
    }

    // Input function to take values from the user
    void input() {
        char empName[50], empDept[50];
        double empSalary, empYears;

        std::cout << "Enter employee name: ";
        std::cin.getline(empName, sizeof(empName));

        std::cout << "Enter employee department: ";
        std::cin.getline(empDept, sizeof(empDept));

        std::cout << "Enter employee salary: ";
        std::cin >> empSalary;

        std::cout << "Enter years of service: ";
        std::cin >> empYears;

        // Free existing memory before dynamic allocation
        delete[] name;
        delete[] department;

        // Dynamic allocation for name
        name = new char[strlen(empName) + 1];
        strcpy(name, empName);

        // Dynamic allocation for department
        department = new char[strlen(empDept) + 1];
        strcpy(department, empDept);

        salary = empSalary;
        yearsOfService = empYears;
    }

    // Show function to display employee information
    void show() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
        std::cout << "Years of Service: " << yearsOfService << " years" << std::endl;
    }

    // Destructor to free allocated memory
    ~Employee() {
        delete[] name;
        delete[] department;
    }
};

int main() {
    // Test the functionality of the Employee class
    Employee emp1; // Parameterless constructor
    emp1.show();

    Employee emp2("John Doe", "IT", 50000.0, 3.5); // 4-argument parameterized constructor
    emp2.show();

    Employee emp3 = emp2; // Copy constructor
    emp3.show();

    emp1.input(); // Input function
    emp1.show();

    return 0;
}
