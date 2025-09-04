#include <iostream>
#include <cstring>
using namespace std;
class employee
{
    char *name;
    char *dpt;
    double salary;
    double years_experince;

public:
    employee() : name(nullptr), dpt(nullptr), salary(0.0), years_experince(0.0) {}
    employee(char *n, char *d, double s, double e) : salary(s), years_experince(e)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        dpt = new char[strlen(d) + 1];
        strcpy(dpt, d);
    }
    employee(const employee &other) : salary(other.salary), years_experince(other.years_experince)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        dpt = new char[strlen(other.dpt) + 1];
        strcpy(dpt, other.dpt);
    }
    void input()
    {
        char arr_name[100];
        char arr_dpt[100];
        cin.getline(arr_name, 100);
        cin.getline(arr_dpt, 1000);
        cout << "Enter salary: ";
        cin >> salary;

        cout << "Enter years of service: ";
        cin >> years_experince;
    }
    void show()
    {
        cout << "name ::" << name << endl;
        cout << "department ::" << dpt << endl;
        cout << "salary:: " << salary << endl;
        cout << "experince in years :: " << years_experince << endl;
    }
    ~employee()
    {
        delete[] name;
        delete[] dpt;
    }
};
int main(){
    employee o2,o4;
    o2.show();
    employee o1("naveed ","cse",40554,2.5);
    o1.show();
    employee o3(o1);
    o3.show();
    o4.input();
    o4.show();




    return 0;
}



