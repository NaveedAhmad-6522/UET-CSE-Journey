#include <iostream>
using namespace std;
class base{
    public:
    int x;
    int y;
    public:
    virtual void display(){
        cout<<"this is base class (x , y)  ("<<x<<" , " <<y<<")"<<endl;
    }

};
class derived :public base{
     public:
    int x;
    int y;
    public:
    void display(){
        cout<<"this is derived class (x , y)  ("<<x<<" , " <<y<<")"<<endl;
    }

};

int main(){
    base *pointer;
    derived obj;
    pointer=&obj;
    pointer->display();


    return 0;
}