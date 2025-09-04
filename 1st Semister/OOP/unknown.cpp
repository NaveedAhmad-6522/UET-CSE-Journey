#include <iostream>
using namespace std;
 class complex{
    friend complex setdata(complex o1,complex o2);
    int static counter;
    int real,img;
public:
    void setdata(){

    cout<<"enter the real and img part of complecx number \n";
    cout<<"complex number :"<<counter++<<endl;
    cin>>real>>img;

    }
    void display(){
    cout<<"entered complex number :: " <<real<<"+"<<img<<"i"<<endl;


    }


};

complex setdata(complex o1,complex o2){
    complex o3;
    o3.real=o1.real+o2.real;
    o3.img=o1.img+o2.img;


}
int mian(){
complex c1,c2,c3;
c1.setdata();
c1.display();

c2.setdata();
c2.display();

c3=setdata(c1,c2);
c3.display();
return 0;
}

