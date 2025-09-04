#include <iostream>

using namespace std;
//single inheritance
class  A{
    // base/parent or super class
    int p1;
    protected:
    int p2;
    public:  
    int p3;
    A():p1(1),p2(2),p3(3){}
    void showA(){
        cout<<"private data   :\n"<<p1<<endl;
        cout<<"protected  data:\n"<<p2<<endl;
        cout<<"public    data :\n"<<p3<<endl;
    }



};
class B:public A{
    int p4;
    public:
    B():A(),p4(4){}
    void showB(){
        showA();
        cout<<"B's private data :\n"<<p4<<endl;

    }
    };
    class C:public B{
    int p5;
    public:
    C():B(),p5(32){}
    void showC(){
        showB();
        cout<<"C's private data :\n"<<p5<<endl;

    }
    };

    

    

int main(){
    A objA;
    B objB;
    C objC;

    /*.showA();
    objA.p3=10;
    objA.showA();
    objB.showB();*/
     objC.showC();


    return 0;
}