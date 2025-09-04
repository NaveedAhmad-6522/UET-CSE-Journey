#include <iostream>
using namespace std;

void myswap(){
	int x,y,temp;
	cout<<"enter x \n";
	cin>>x;
		cout<<"enter y \n";
	
	cin>>y;
	temp=x;
	x=y;
	y=temp;
	cout<<"after swapping \n";
	cout<<"x:"<<x<<endl;
	cout<<"y:"<<y<<endl;
	temp=x;
	x=y;
	y=temp;
		cout<<"after swapping \n";
	cout<<"x:"<<x<<endl;
	cout<<"y:"<<y<<endl;
	
	
	
}
main(){
	myswap();
}
