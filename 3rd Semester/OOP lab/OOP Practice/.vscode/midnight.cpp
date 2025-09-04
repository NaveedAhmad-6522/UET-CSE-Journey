#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class company {
    char* name;
    string department;
    int employee_id;
    static int employee_number;

public:
    company() : name(nullptr), department(""), employee_id(0) {}

    company(char* n, string s, int id) : department(s), employee_id(id) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    company(const company& obj) : department(obj.department), employee_id(obj.employee_id) {
        // Shallow copy
        // name = new char[strlen(obj.name) + 1];
        // strcpy(name, obj.name);
        name = obj.name;
    }

    void display() {
        cout << "name: " << name << endl;
        cout << "ID  : " << employee_id << endl;
        cout << "DPT : " << department << endl;
    }

    void modifyName(char newChar) {
        // Modify the name data
        name[0] = newChar;
    }
};

// Initialize the static variable outside the class
int company::employee_number = 0;

int main() {
    company o2("naveed", "IT", 900);
    company o1(o2);
    
    // Display initial data
    cout << "Initial data:" << endl;
    o1.display();
    o2.display();

    // Modify data using public member function
    o1.modifyName('N');

    // Display data after modification
    cout << "After modification:" << endl;
    o1.display();
    o2.display(); // Both objects should now reflect the modification

    return 0;
}
