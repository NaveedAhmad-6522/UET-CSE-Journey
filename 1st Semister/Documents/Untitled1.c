#include <iostream>
using namespace std;
class complex{
	int real_part;
	int img_part;
	friend complex ToSum(complex o1,complex o2);
public:
	void setData(int a,int b){
		a=real_part;
		b=img_part;

	}
	void display(){
		cout<<"entered complex number is: "<<real_part<<"+"<<img_part<<"i"<<endl;
	}
};
complex ToSum(complex o1,complex o2){
	complex o3;
	o3.real_part=o1.real_part+o2.real+_part;
	o3.img_part=o1.img_part+o2.img_part;
	return o3;

}
main(){
	complex a,b,c;
	a.setData(3,5);
	a.display();
	b.setData(6,3);
	b.display();
	c.ToSum(complex a,complex b);
	c.display();
}
