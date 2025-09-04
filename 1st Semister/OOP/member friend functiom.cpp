#include <iostream>
using namespace std;
class complex;
class calculator{
	public:
		int add(int a,int b){
			return a+b;
		}
			int sumrealcomplex(complex ,complex );
		
		
};
class complex{
	int real_part;
	int img_part;
	public:
		friend int calculator::sumrealcomplex(complex o1,complex o2);
		void setdata(int a,int b){
		a=real_part;
		b=img_part;
		
		}
		void display(){
			cout<<"compolex number is: "<<real_part<<"+"<<img_part<<"i"<<endl;
		}
	
};
int calculator::sumrealcomplex(complex o1,complex o2){
			return (o1.a+o2.a);
		}
int main(){
	 complex o1,o2;
	 o1.setdata(3,4);
	 o2.setdata(4,6);
	 calculator o3;
	 int result=o3.sumrealcomplex(o1,o2);
	 cout<<result;
	 
	 
}
