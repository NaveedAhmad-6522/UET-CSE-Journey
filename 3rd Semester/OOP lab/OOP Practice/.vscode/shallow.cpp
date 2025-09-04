#include <iostream>
using namespace std;
class complex{
private:
double re, im;
public:

complex(): re(0),im(0) { }
complex(double r, double i): re(r), im(i) { }
complex(const complex &c){ // custom copy constructor - Shallow
cout << "\nIn Custom Copy Constructor [Shallow]" << endl;
re = c.re; im = c.im;
}
void show(){
cout<<"Complex Number: "<<re<<"+"<<im<<"i"<<endl;
}
};
int main(){
complex c1(5,2.5);
c1.show();
// use of default copy constructor
// call by two ways
complex c2(c1); // 1. function notation
c2.show();
complex c3 = c2; // 2. assignment operator
c3.show();
return 0;
}