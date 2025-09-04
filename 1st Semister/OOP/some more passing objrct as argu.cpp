#include <iostream>
using namespace std;

class complex{
	friend complex sumBy(complex o1,complx o2);
	int a,b;
	public:
		void setData(){
			cout<<"enter real and img part ::"<<endl;
			cin>>a>>b;
		}
		void display(){
			cout<<"the complex number \n";
			cout<<a<<"+"<<b<<"i \n";
		}
};

complex sumBy(complex o1,complx o2){
	
	a=o1.a+o2.a;
    b=o1.b+o2.b;
	
}
int main(){
	complex c1,c2,c3;
	c1.setData();
	c1.display();
	
	c2.setData();
	c2.display();
	c3=sumBy(c1,c2);
	c2.display();
}
