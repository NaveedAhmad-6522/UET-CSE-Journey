#include <iostream>

using namespace std;
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