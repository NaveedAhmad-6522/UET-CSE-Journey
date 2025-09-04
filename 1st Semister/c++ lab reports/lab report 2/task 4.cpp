//Write a C++ program to prompt the user to input 3 integer values and print these values 
//in forward and reversed order.
#include <iostream>
using namespace std;
main()
{
	int a,b,c;
	
	cout<<"type a=";
	cin>>a;
	cout<<"type b=";
	cin>>b;
	cout<<"type c=";
	cin>>c;
	
	cout<<"forward orderd ;"<<a<<b<<c<<endl;
	cout<<"reversed orderd ;"<<c<<b<<a<<endl;
	return 0;
}
