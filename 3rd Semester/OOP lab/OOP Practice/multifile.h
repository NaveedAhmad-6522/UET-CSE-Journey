#include <iostream>
#include <cstring>
using namespace std;
/*C++: Create a class called employee. This class maintains information about name (char*),
department (char*), salary (double), and period of service in years (double).
1. Provide a parameterless constructor to initialize the data members to some fixed values.

2. Provide a 4-argument parameterized constructor to initialize the members to values sent
from calling function.
a. (You have to make dynamic allocation for both name and department data
members in constructor.)

3. Provide a copy-constructor that performs the deep copy of the data members.
4. Provide an input function that takes all the values from user during run-time.
5. Provide a show function that shows all the information about a specific employee to user.
6. Provide a destructor to free the memory allocated to name and department in constructor.
Write all the member function outside a C++ class. Write a driver program to test the
functionality of the above-mentioned class.*/
class employee
{
    char *name;
    char *department;
    double salary;
    double period_ofService;
    public:
    employee():name(nullptr),department(nullptr),salary(0.0),period_ofService(0.0){}
    employee(char *nme,char *dpt, double s,double ps):name(nme),department(dpt),salary(s),period_ofService(ps){
        name=new char[sizeof(name)-1];
        strcpy(name,nme);
        department=new char[sizeof(department)-1];
        strcpy(department,dpt);
    }
    employee(const employee&obj){
          name=new char[sizeof(obj.name)-1];
          strcpy(name,obj.name);
        department=new char[sizeof(obj.department)-1];
        strcpy (department,obj.department);
        salary=obj.salary;
        period_ofService=obj.period_ofService;
    
    }
    void input(){
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter department"<<endl;
        cin>>department;
        cout<<"enter salary"<<endl;
        cin>>salary;
        cout<<"enter service in years"<<endl;
        cin>>period_ofService;

    }
    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"eDepartment:"<<department<<endl;
        cout<<"Salary:"<<salary<<endl;
        cout<<"Service:"<<period_ofService<<endl;
    }

};