#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/**/
class employee
{
protected:
    int employee_id;
    string name;

public:
    employee() {}
    employee(int id,  string n) : employee_id(id), name(n) {}
    void display()
    {
        cout << "employee id ::" << employee_id;
        cout << "\n employee name ::\n"
             << name;
    }
};
class manager : public employee
{
    string dpt;

public:
    manager(int id, string n, string d) : employee(id, n), dpt(d) {}
    void set(string department)
    {
        dpt = department;
    }
    string get()
    {
        return dpt;
    }
    void manageTeam()
    {
        cout << "managing the team in the  " << dpt << "department \n";
    }
    void assignTasks()
    {
        cout << "Assigning tasks to the team in the ___department::" << dpt << endl;
    }
};
class intern : public employee
{
    string superviser;
    int duration;

public:
    intern(int id, string n,  string s, int t) : employee(id, n), superviser(s), duration(t) {}
    void trackProgress()
    {
        cout << "Tracking progress of the intern under: " << superviser << " for: " << duration << " months" << endl;
    }
    void reportActivities()
    {
        cout << "Reporting activities to: " << superviser << " regularly" << endl;
    }
};

int main()
{
    manager manager(1, "John Doe", "IT");
    manager.display();
    manager.manageTeam();
    manager.assignTasks();

    cout << "\n";

    intern intern(2, "Alice Smith", "Supervisor123", 32);
    intern.display();
    intern.trackProgress();
    intern.reportActivities();

    return 0;
}