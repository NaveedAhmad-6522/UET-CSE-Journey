#include <iostream>
using namespace std;
//pointer lab #8 & 9


int main(){
	int x=10;
	cout<<&x;
	int*p;
	p=&x;
	cout<<p<<endl;
	cout<<*p<<endl;
	//p++;
	//cout<<p;
	*p=20;
	cout<<x<<endl;
	
	int*q=&x;
	*q=30;
	cout<<*p<<endl;
	x++;
	cout<<*q<<endl;
	
    cout<<(*p)++<<endl;
	cout<<*p<<endl;
	cout<<++*pendl;
	cout<<*p<<endl;
	

	
	
	return 0;
}
