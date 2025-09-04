#include <iostream>
using namespace std;

class complex{
	friend complex sum(complex o1,complex o2);
	int real_part;
	int img_part;
	public:
		static int count;
		void setdata(int a,int b){
			real_part=a;
			img_part=b;
		
		}
		void display(){
			cout<<"number :"<<count<<endl;
			cout<<"compolex number is: "<<real_part<<"+"<<img_part<<"i"<<endl;
			count++;
		}
};
//friend function
//not member function but permeted to access private parts of class
complex sum(complex o1,complex o2){
	complex toSum;
	toSum.setdata((o1.real_part+o2.real_part),(o1.img_part+o2.img_part));
	return toSum;
	
}
int complex::count=3;
int main(){
	complex a1,a2,a3;
	a1.setdata(3,5);
	a1.display();
	a2.setdata(4,5);
	a2.display();
	
	a3=sum(a1,a2);
	a3.display();
}
