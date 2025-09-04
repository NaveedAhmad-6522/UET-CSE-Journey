#include <iostream>
using namespace std;

/*Write a program to develop student information system. This system should be able to 
take the student’s credentials, like name, reg no and semester no, as input and store them 
in a structure object Student_t. The system should be capable of storing the information 
of multiple students.
And it should be capable of displaying the student’s information, when asked to do so, 
via reg no*/

struct student{
	string name;
	string reg;
	int sem_no;
	
	
};

main(){
	int x;
	cin>>x;
student	student[x];

cout<<"enter student information"<<endl;
  
  for(int i=0;i<x;i++){
  	cout<<"information of "<<i+1<<endl;
  	cout<<"enter name \n";
  	cin>>student[i].name;
  		cout<<"enter reg \n";
  	cin>>student[i].reg;
  	cout<<"enter sem no \n";
  	cin>>student[i].sem_no;
  }
	
	string regNoToSearch;
    cout << "Enter registration number to display student information: ";
    cin >> regNoToSearch;
	bool found=false;
	for(int i=0;i<x;i++){
		if(student[i].reg==regNoToSearch){
			found=true;
			cout<<"student found \n";
			cout<<"name :"<<student[i].name<<endl;
			cout<<"reg number :"<<student[i].reg<<endl;
			cout<<"sem no :"<<student[i].sem_no<<endl;
			break;
		}
	}
	if(!found){
		cout<<"not found \n";
	}
	
}
