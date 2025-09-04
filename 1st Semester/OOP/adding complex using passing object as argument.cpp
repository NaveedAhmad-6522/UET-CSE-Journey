#include <iostream>
using namespace std;
class complex{
	int real_part;
	int img_part;
	public:
		void setData(){
			cout<<"enter real part: ";
			cin>>real_part;
			cout<<"enter imagnery part: ";
			cin>>img_part;
		}
		void sumofcomplex(complex o1,complex o2){
		real_part=o1.real_part+o2.real_part;
		img_part=o1.img_part+o2.img_part;			
		}
		void display(){
			cout<<"real part: "<<real_part<<endl;
			cout<<"img  part: "<<img_part<<"i"<<endl;
			cout<<"standred form: "<<real_part<<"+"<<img_part<<"i"<<endl;
		}
		void show(){
			cout<<"after addition \n";
		}
};
int main(){
	complex c1,c2,c3;
	c1.setData();
	c1.display();
	
	c2.setData();
	c2.display();
	
	
	c3.sumofcomplex(c1,c2);
	c3.show();
	c3.display();
}
