#include <iostream>
#include <cmath>
using namespace std;

char func(int marks){
	if(marks>=90){
		return 'A';
	}
		else if(marks>=80){
		return 'B';
	}
		else if(marks>=70){
		return 'C';
	}	else if(marks>=60){
		return 'D';
	}
	else{
		return 'F';
	}
}
int main(){
	int marks;
string name;
	cout<<"enter your name"<<endl;
	getline(cin,name);
	cout<<"enter your marks"<<endl;
	cin>>marks;
	cout<<"your grade is"<<endl;
	cout<<func(marks)<<endl;
	return 0;
	
	
	
	
}
