/*. Write a program to find Factorial of a number.*/
#include <iostream>
using namespace std;

int main(){
	int num;
	cout<<"enter a  +ve number ::"<<endl;
	cin>>num;
	if(num<0){
		cout<<"facrorial of -ve number not exsist";
		return 0;
	}
	int fact=1;
	for(int i=1;i<=num;i++){
		fact=fact*i;
		
	}
	cout<<"factorial of the"<<" "<<num<<" is :"<<fact<<endl;
	return 0;
}
