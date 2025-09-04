#include <iostream>
using namespace std;
/*Write a C++ program where you create 2 functions (percentage, GPA) and a 3rd function 
called caller, the caller will have one integer and a pointer to function as parameters. In the 
main function you must prompt the user to enter marks, then prompt him again to ask what 
he wants to find out, GPA (assume 90-100 marks = A = 4.0 GPA and so on) based on 
marks or percentage based on marks. Then call the caller function accordingly*/
float percentage(int marks){
	return static_cast<float>(marks)/100*100;
	
}
float GPA(int marks){
	  if (marks >= 90 && marks <= 100) {
        return 4.0;
    } else if (marks >= 80 && marks < 90) {
        return 3.7;
    } else if (marks >= 70 && marks < 80) {
        return 3.3;
    } else if (marks >= 60 && marks < 70) {
        return 3.0;
    } else if (marks >= 50 && marks < 60) {
        return 2.7;
    } else if (marks >= 40 && marks < 50) {
        return 2.3;
    } else {
        return 0.0;
    }
	
}

caller(int marks,float(*ptrfunction)(int)){
	float result=(*ptrfunction)(marks);
	cout<<"result: "<<result;
	
}
main(){
	int marks;
	cout<<"marks \n";
	cin>>marks;
	int choice;
	cout<<"enter 1 for gpa"<<endl;
	cout<<"enter 2 for percentage \n";
	cin>>choice;
	if(choice==1){
		caller(marks,GPA);
	}
	else if(choice==2){
		caller(marks,percentage);
	}
	else{
		cout<<"invalid choice!";
	}
}
