#include <iostream>
using namespace std;
int main(){
	int a;
	int b;
	int d;
	int *c;
	cout <<"enter values"<<endl;
	cin>>a>>b;;
	c=&d;
	*c=a+b;
	cout<<"sum = "<<*c<<&d<<endl;
	return 0;
	
}
