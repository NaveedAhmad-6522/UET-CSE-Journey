l#include <iostream>
#include <string>
using namespace  std;

struct students{
	string name;
	string registeration_id;
	string semister_number;
	string gpa;
};

main(){	
int x;
cout<<"enter number of students \n";
cin>>x;
students number[x];
cout<<"enter students detiles \n ";
for(int i=0;i<x;i++){
	cout<<"studnt "<<i+1<<endl;
	cout<<"name of student"<<endl;
	cin>>number[i].name;
	cout<<"registration number of student"<<endl;
	cin>>number[i].registeration_id;
	cout<<"gpa of student"<<endl;
	cin>>number[i].gpa;
	cout<<"semister number of student"<<endl;
	cin>>number[i].semister_number;
}
	
string 	search;
cout<<"enter registration_id to find detiles \n";
cin>>search;
      
     
      for(int i=0;i<x;i++){
      	if(number[i].registeration_id==search){
      		cout << "Student Found!\n";
        cout << "Name: " << number[i].name << endl;
        cout << "Registration Number: " << number[i].registeration_id << endl;
        cout << "Semester Number: " << number[i].semister_number<< endl;
        cout << "student GPA: " << number[i].gpa<< endl;
		  break;
		  return 0;
		  }
		  
	  }
	
      for(int i=0;i<x;i++){
      	if(number[i].registeration_id!=search){
      		cout << "Student Not Found!\n";
      	}
	}
		
}

