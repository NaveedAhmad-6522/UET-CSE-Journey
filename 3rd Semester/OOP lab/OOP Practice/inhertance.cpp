#include <iostream>
#include <cstring>
using namespace std;
/*Create a class called Employee with two protected data members: employeeID (integer) and name
(string). Provide a 2-argument constructor: one argument to initialize the employeeID and the other
argument to initialize the name. Provide a displayDetails() function for displaying the details of the
employee, including their name and employee ID.
Derive a class called Manager publicly from the Employee class. Add a new data member, department
(string), to represent the department the manager oversees. Implement a 3-argument constructor
that takes employee id, name, and department and initialized them. Include setter and getter
functions for the department. Provide function manageTeam() to manage the team that shows the
message "Managing the team in the ___ department" where ___ shows the department. Provide
function assignTasks() to assign tasks that shows the message "Assigning tasks to the team in the ___
department" where ___ shows the department.
Derive another class called Intern publicly from the Employee class. Add new members, supervisor
(string) and duration (integer), to represent the intern's supervisor and the duration of their
internship, respectively. Implement appropriate constructor to initialize the intern's details, including
the supervisor and duration of the internship. Provide a function to track the progress of the intern
trackProgress() that shows the message "Tracking progress of the intern under ___ for ___ months”
where first ___ shows the supervisor and the second ___ shows the duration. Provide a function
reportActivities() to report on their activities to the supervisor. It shows the message "Reporting
activities to ___ regularly" where ___ shows the supervisor.
Write a main function to test the functionality of these classes, creating instances of employees,
managers, and interns, and invoking various member functions to demonstrate their behavior within
the company environment.*/
class employee{
protected :
int employee_id;
string name;
public:
employee():employee_id(0),name(" "){}
employee(int id,string n):employee_id(id),name(n){}
void display(){
    cout<<"Employee id:"<<endl;
    cout<<"Name:"<<name<<endl;
}

};
class manger:public employee{
    protected:
    string department ;
    public:
    manger(int id,string n,string dpt):employee(id,n),department(dpt){}
    void getter(){
        cout<<"enter department:"<<endl;
        cin>>department;
    }
    void setter(){
        cout<<"Department:"<<department<<endl;

    }
    

};