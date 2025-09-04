#include <iostream>
#include <cstring>

class Employee {
private:
    char* name;
    char* department;
    double salary;
    double yearsOfService;

public:
   
    Employee() : name(nullptr), department(nullptr), salary(0.0), yearsOfService(0.0) {}

    Employee(const char* n, const char* d, double s, double y) : salary(s), yearsOfService(y) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        department = new char[strlen(d) + 1];
        strcpy(department, d);
    }
    Employee(const Employee& other) : salary(other.salary), yearsOfService(other.yearsOfService) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        department = new char[strlen(other.department) + 1];
        strcpy(department, other.department);
    }

    void input() {
        char n[100], d[100];
        std::cout << "Enter name: ";
        std::cin.ignore(); 
        std::cin.getline(n, 100);

        std::cout << "Enter department: ";
        std::cin.getline(d, 100);

        std::cout << "Enter salary: ";
        std::cin >> salary;

        std::cout << "Enter years of service: ";
        std::cin >> yearsOfService;

        name = new char[strlen(n) + 1];
        strcpy(name, n);

        department = new char[strlen(d) + 1];
        strcpy(department, d);
    }

    void show() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Years of Service: " << yearsOfService << std::endl;
    }

    ~Employee() {
        delete[] name;
        delete[] department;
    }
};

int main() {
   
    Employee emp1; 
    emp1.show();

    Employee emp2("John Doe", "IT", 50000.0, 5.5); 
    emp2.show();

    Employee emp3 = emp2; 
    emp3.show();

    Employee emp4;
    emp4.input(); 
    emp4.show();

    return 0;
}