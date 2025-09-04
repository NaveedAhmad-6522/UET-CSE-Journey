/*Write a C++ program where you take two values in two variables from user, add the values 
of the two variables and put it into a third variable using a pointer. you must you only one 
pointer.*/
#include <iostream>
using namespace std;

void fun(int x,int y ,int*sum){
	*sum=x+y;
}
int main(){
	int x,y;
	cout<<"enter x and y: \n";
	cin>>x>>y;
	int result=x+y;
	int*sum=&result;
	fun( x,y,sum);
	cout<<"sum: "<< *sum;
	
}
