//Write a program to calculate area of a circle having its radius (ask user to input radius).

#include <iostream>
using namespace std;

main()
{
	float pi=3.1314;
int r,area;
	 
	cout<<"enter radius of circle=";
	cin>>r;
	
	area=pi*r*r;
	
	cout<<"area of circle:"<<area<<endl;
	return 0;
	
	
}
