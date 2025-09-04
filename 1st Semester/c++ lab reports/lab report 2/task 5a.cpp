//Write a program to swap two variables values with and without using third variables.

//with using third variable.
#include <iostream>
using namespace std;
main()
{
int a;
int b;
//int c;
   
   cout<<"value of a:";
   cin>>a;
   cout<<"value of b:";
   cin>>b;
    
	a=a+b;
	b=a-b;
	a=a-b;
	
	cout<<"after swaping:";
	cout<<"value of a:"<<a<<endl;
	cout<<"value of b:"<<b;

	
	return 0;
	
	
	
}
















