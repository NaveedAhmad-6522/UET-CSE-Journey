#include <iostream>
#include <cstring>
using namespace std;

class employee {
    char *name;
    char *dpt;
    double salary;
    double years_experience;

public:
    employee() : name(nullptr), dpt(nullptr), salary(0.0), years_experience(0.0) {}
    
    employee(char *n, char *d, double s, double e) : salary(s), years_experience(e) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        dpt = new char[strlen(d) + 1];
        strcpy(dpt, d);
    }

    employee(const employee &other) : salary(other.salary), years_experience(other.years_experience) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        dpt = new char[strlen(other.dpt) + 1];
        strcpy(dpt, other.dpt);
    }

    void input() {
        char arr_name[100];
        char arr_dpt[100];

        cout << "Enter name: ";
        cin.getline(arr_name, 100);

        cout << "Enter department: ";
        cin.getline(arr_dpt, 100);

        cout << "Enter salary: ";
        cin >> salary;

        cout << "Enter years of service: ";
        cin >> years_experience;

        cin.ignore(); // Clear the newline character from the input buffer
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Department: " << dpt << endl;
        cout << "Salary: " << salary << endl;
        cout << "Experience in years: " << years_experience << endl;
    }

    ~employee() {
        delete[] name;
        delete[] dpt;
    }
};

int main() {
    employee o2, o4;

    cout << "Details of o2:" << endl;
    o2.show();

    employee o1("naveed", "cse", 40554, 2.5);
    cout << "Details of o1:" << endl;
    o1.show();

    employee o3(o1);
    cout << "Details of o3 (copied from o1):" << endl;
    o3.show();

    o4.input();
    cout << "Details of o4 (user input):" << endl;
    o4.show();

    return 0;
}
