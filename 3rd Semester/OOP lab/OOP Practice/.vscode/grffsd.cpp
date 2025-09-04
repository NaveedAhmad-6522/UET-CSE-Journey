#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char *name;
    char *department;
    double salary;
    double serviceYears;

public:
    // Parameterless constructor
    Employee() : name(nullptr), department(nullptr), salary(0.0), serviceYears(0.0)
    {
        // Allocate memory for name and department
    }
    Employee(char *ptr1, char *ptr2, double s, double sy) : salary(s), serviceYears(sy)
    {
        name = new char[strlen(ptr1) + 1];
        strcpy(name, ptr1);
        department = new char[strlen(ptr2) + 1];
        strcpy(department, ptr2);
    }
    Employee(Employee &obj) : salary(obj.salary), serviceYears(obj.serviceYears)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        department = new char[strlen(obj.department) + 1];
        strcpy(department, obj.department);
    }
    void display()
    {
        cout << "name" << name << endl;
        cout << "dpt:" << department << endl;
        cout << "salary: " << salary << endl;
        cout << "experince: " << serviceYears << endl;
    }
};

int main()
{
    Employee o1("name", "department", 12.12, 43.2);
    Employee o2("drfgh243", "gdhe", 12.1322, 43.322);
    Employee o3,o4;
    o3=o2;
    o1.display();
    o2.display();
    o3.display();

     return 0;
}