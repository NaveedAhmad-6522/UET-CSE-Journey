//Write a program to swap two variables values with and without using third variables.

//without using third variable.
#include <iostream>
using namespace std;
main()
{
int a;
int b,c;
   
   cout<<"value of a:";
   cin>>a;
   cout<<"value of b:";
   cin>>b;
   
   c=a;
  a=b;
   b=c;
   
    
	cout<<"after swaping:";
		cout<<"value of a:"<<a<<endl;
	cout<<"value of b:"<<b;

	
	return 0;
	
	
	
}



