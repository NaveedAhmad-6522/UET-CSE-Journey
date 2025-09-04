#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class employee
{
    char *name;
    char *department;
    double salary;
    double service_years;

public:
    employee() : name(nullptr), department(nullptr), salary(0.0), service_years(0.0) {}
    employee(char n[], char *dpt, double s, double y) : salary(s), service_years(y)
    {
        name = new char[strlen(name) + 1];
        strcpy(name, n);
        department = new char[strlen(department) + 1];

        strncpy(department, dpt, strlen(department) + 1);
    }
    employee(employee &obj) : salary(obj.salary), service_years(obj.service_years)
    {
        name = new char[strlen(obj.name) + 1];
        strncpy(name, obj.name, strlen(name) + 1);
        department = new char[strlen(obj.department) + 1];
        strncpy(department, obj.department, strlen(department) + 1);
    }

    void input()
    {
        cout << "Enter name: " << endl;
        char buffer[100];
        cin >> buffer;
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);

        cout << "Enter department: " << endl;
        cin >> buffer;
        department = new char[strlen(buffer) + 1];
        strcpy(department, buffer);

        cout << "Enter salary: " << endl;
        cin >> salary;

        cout << "Enter service in years: " << endl;
        cin >> service_years;
    }

    void display()
    {
        cout << "name : " << name << endl;
        cout << " department : " << department << endl;
        cout << " salary : " << salary << endl;
        cout << "enter service in years : " << service_years << endl;
    }
    ~employee()
    {
        delete[] name;
        delete[] department;
    }
};

int main()
{
    employee o1("naveed ", "IT", 250, 2.3);
    employee o2("asad", "civil", 543, 3.4);
    o1.display();
    cout << endl;
    o2.display();
    cout << "copy constructor deep" << endl;
    employee o3(o2);
    o3.display();
    cout << "updated o2" << endl;
    o2.input();
    o2.display();
    cout << "showing that o3 not change with o2 b/c of deep copy" << endl;
    o3.display();

    return 0;
}