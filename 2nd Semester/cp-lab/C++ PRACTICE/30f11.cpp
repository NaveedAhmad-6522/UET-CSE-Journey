/*Write a program to develop student information system. This system should be able to 
take the student’s credentials, like name, reg no and semester no, as input and store them 
in a structure object Student_t. The system should be capable of storing the information 
of multiple students.
And it should be capable of displaying the student’s information, when asked to do so, 
via reg no*/
#include <iostream>
using namespace std;

struct student{
	string name;
	int number;
	string reg;
};

main(){

int x;
cin>>x;
student student[x];
 for(int i=0;i<x;i++){
 	 cout<<"enter information of :"<< i+1	<<endl;
 	 cout<<"enter name \n";
 	 cin>>student[i].name;
 	 cout<<"enter semister number \n";
 	 cin>>student[i].number;
 	 cout<<"enter reg number number \n";
 	 cin>>student[i].reg;
 }
 
  string searchRegNo;
    cout << "Enter registration number to search: ";
    cin >> searchRegNo;
 
 bool found = false;
for (int i = 0; i < x; i++) {
    if (student[i].reg == searchRegNo) {
        cout << "Student Found!\n";
        cout << "Name: " << student[i].name << endl;
        cout << "Registration Number: " << student[i].reg << endl;
        cout << "Semester Number: " << student[i].number << endl;
        found = true;
        break;
    }
}

if (!found) {
    cout << "Student not found.\n";
}

	
}
