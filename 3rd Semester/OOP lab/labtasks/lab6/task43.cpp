#include <iostream>
#include <cstring>

class Employee {
private:
    char* name;
    char* department;
    double salary;
    double yearsOfService;

public:
    // Parameterless constructor
    Employee();

    // Parameterized constructor
    Employee(const char* n, const char* d, double s, double y);

    // Copy constructor
    Employee(const Employee& other);

    // Input function
    void input();

    // Show function
    void show() const;

    // Destructor
    ~Employee();
};

// Parameterless constructor definition
Employee::Employee() : name(nullptr), department(nullptr), salary(0.0), yearsOfService(0.0) {
}

// Parameterized constructor definition
Employee::Employee(const char* n, const char* d, double s, double y) : salary(s), yearsOfService(y) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    department = new char[strlen(d) + 1];
    strcpy(department, d);
}

// Copy constructor definition
/*Employee::Employee(const Employee& other) : salary(other.salary), yearsOfService(other.yearsOfService) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    department = new char[strlen(other.department) + 1];
    strcpy(department, other.department);
}
*/
// Input function definition
void Employee::input() {
    char tempName[100];
    char tempDept[100];

    std::cout << "Enter name: ";
    std::cin.getline(tempName, 100);

    std::cout << "Enter department: ";
    std::cin.getline(tempDept, 100);

    std::cout << "Enter salary: ";
    std::cin >> salary;

    std::cout << "Enter years of service: ";
    std::cin >> yearsOfService;

    delete[] name; // Free existing memory
    delete[] department; // Free existing memory

    name = new char[strlen(tempName) + 1];
    strcpy(name, tempName);

    department = new char[strlen(tempDept) + 1];
    strcpy(department, tempDept);

    std::cin.ignore(); // Clear the input buffer
}

// Show function definition
void Employee::show() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Years of Service: " << yearsOfService << std::endl;
}

// Destructor definition
Employee::~Employee() {
    delete[] name;
    delete[] department;
}

// Driver program
int main() {
    Employee emp1; // Parameterless constructor
    std::cout << "Details of emp1:" << std::endl;
    //emp1.show();

    Employee emp2("John Doe", "IT", 50000.0, 3.5); // Parameterized constructor
    std::cout << "\nDetails of emp2:" << std::endl;
    emp2.show();

    Employee emp3 = emp2; // Copy constructor
    std::cout << "\nDetails of emp3 (copied from emp2):" << std::endl;
    emp3.show();

    Employee emp4;
    std::cout << "\nEnter details for emp4:" << std::endl;
    emp4.input(); // Input function
    std::cout << "\nDetails of emp4:" << std::endl;
    emp4.show();

    return 0;
}
