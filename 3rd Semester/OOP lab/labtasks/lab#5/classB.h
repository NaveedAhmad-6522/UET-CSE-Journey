#include <iostream>
#include "classA.h"
using namespace std;
 class B:public A{
    int p4;
    public:
    B():p4(4){}
    void showB(){
        cout<<"B's private data :\n"<<p4<<endl;

    }
    };