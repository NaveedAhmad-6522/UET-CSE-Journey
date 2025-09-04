#include <iostream>
#include <string>
using namespace std;

float percentage(int marks){
	return static_cast <float>(marks)/100*100;
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
void caller(int marks,float(*ptrfun)(int)){
	float result = (*ptrfun)(marks);
	cout<<result;
	
}
main(){
	int marks;
	cout<<"enter marks: \n";
	cin>>marks;
	
char choice;

	cout<<"enter your choice g,p \n";
		cin>>choice;
	if(choice=='g'){
		caller(marks,GPA);
	}
	else if(choice=='p'){
		caller(marks,percentage);
	}
	else{
		cout<<"ivnvalide choice!";
	}
}
