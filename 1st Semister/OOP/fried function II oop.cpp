#include <iostream>
using namespace std;

class complex{
	friend complex sum(complex o1,complex o2);
	int real_part;
	int img_part;
	public:
		void setdata(){
		cin>>real_part;
		cin>>img_part;
		
		}
		void display(){
			cout<<"compolex number is: "<<real_part<<"+"<<img_part<<"i"<<endl;
		}
};
//friend function
//not member function but permeted to access private parts of class
complex sum(complex o1,complex o2){
	complex toSum;
	toSum.real_part=(o1.real_part+o2.real_part);
	toSum.img_part=(o1.img_part+o2.img_part);
	return toSum;


	
}
int main(){
	complex a1,a2,a3;
	a1.setdata();
	a1.display();
	a2.setdata();
	a2.display();
	
	a3=sum(a1,a2);
	a3.display();
}
