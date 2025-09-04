#include <iostream>
using namespace std;

class Input {
protected:
    string name;
    string reg_no;
    int semNo;
	
public:
    Input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter registration number: ";
        cin >> reg_no;
        cout << "Enter semester number: ";
        cin >> semNo;			
    }
    
    ~Input() {
        cout << "end of program\n";
    }
};

class Output : public Input {
public:
    void display() {
        cout << "Name: " << name << endl;
        
        cout << "Registration number: " << reg_no << endl;
        cout << "Semester number: " << semNo << endl;
    }
};

int main() {
    Output obj;
    obj.display();

    return 0;
}

