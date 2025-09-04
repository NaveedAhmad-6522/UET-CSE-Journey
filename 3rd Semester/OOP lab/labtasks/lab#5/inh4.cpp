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
class B{
    int p4;
    public:
    B():p4(4){}
    void showB(){
        cout<<"B's private data :\n"<<p4<<endl;

    }
    };
    class C:public A,public B{ //child of both A B
    int p5;
    public:
    C():A(),B(),p5(32){}
    void showC(){
        showA();
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