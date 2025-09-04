#include <iostream>
#include <cstring>

class Employee {
private:
    static int totalEmployees;
    int employeeId;
    char name[50];
    char designation[50];

public:
    Employee(int id,char empName[50], char empDesignation[50]) {
        employeeId = id;
        strncpy(name, empName, sizeof(name));
        strncpy(designation, empDesignation, sizeof(designation));
        totalEmployees++;
    }

    ~Employee(){
        totalEmployees--;
    }
    void displayEmployee() {
        std::cout << "Employee ID: " << employeeId << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Designation: " << designation << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    static void displayTotalEmployees() {
        std::cout << "Total Employees: " << totalEmployees << std::endl;
    }
    void updateEmployee(int id, char empName[50],  char empDesignation[50]) {
        employeeId = id;
        strncpy(name, empName, sizeof(name));
        strncpy(designation, empDesignation, sizeof(designation));
        std::cout << "Employee records updated successfully." << std::endl;
    }
};

int Employee::totalEmployees = 0;

int main() {
    Employee emp1(1, "John Doe", "Software Engineer");
    Employee emp2(2, "Jane Smith", "HR Manager");
    emp1.displayEmployee();
    emp2.displayEmployee();
    Employee::displayTotalEmployees();
    emp1.updateEmployee(1, "John Doe", "Senior Software Engineer");
    emp2.updateEmployee(2, "Jane Smith", "Senior HR Manager");
    emp1.displayEmployee();
    emp2.displayEmployee();
    return 0;
}
