#include <iostream>
#include <string>
using namespace std;

/* Write a program to develop student information system. This system should be able to 
take the student’s credentials, like name, reg no and semester no, as input and store them 
in a structure object Student_t. The system should be capable of storing the information 
of multiple students.
And it should be capable of displaying the student’s information, when asked to do so, 
via reg no*/

struct student{
	string name;
	string rg_no;
	int   sem_no;
};


main(){
	int size;
	cout<<"enter number of students::  \n";
	cin>>size;
student student[size];

cout<<"enter student in formation :: \n";
int i=0;

do{
	cout<<"student "<<i+1<<"::"<<endl;
	cout<<"enter  name :: \n";
	cin>>student[i].name;
	cout<<"enter registration number :: \n";
	cin>>student[i].rg_no;
		cout<<"enter semister number :: \n";
	cin>>student[i].sem_no;
	i++;
	
}while(i<size);

 string searchRegNo;
    cout << "Enter registration number to search: ";
    cin >> searchRegNo;
 
 bool found = false;
for (int i = 0; i < size; i++) {
    if (student[i].rg_no == searchRegNo) {
        cout << "Student Found!\n";
        cout << "Name: " << student[i].name << endl;
        cout << "Registration Number: " << student[i].rg_no << endl;
        cout << "Semester Number: " << student[i].sem_no << endl;
        found = true;
        break;
    }
}

if (!found) {
    cout << "Student not found.\n";
} 
}

