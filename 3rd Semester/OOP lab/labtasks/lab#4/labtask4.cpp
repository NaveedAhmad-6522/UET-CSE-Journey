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
    A():p1(1),p2(2),p3(3);
    void showA(){
        cout<<"private data :"<<p1<<endl;
         cout<<"protected  data :"<<p2<<endl;
          cout<<"pubkic data :"<<p3<<endl;
    }



};
class B:public A{
    
};
int main(){
    A objA;
    B objB;

    objA.showA();
    objA.p3=10;
    objA.showA();
    objB.showA();


    return 0;
}