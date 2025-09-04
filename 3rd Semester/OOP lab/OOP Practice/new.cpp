#include <iostream>
#include<cstring>
using namespace std;
class opol{
    int real,img;
    public:
    opol():real(0),img(0){}
    opol(int r,int i):real(r),img(i){}
    
    opol operator+ (opol o2){
        opol temp;

       temp. real=real+o2.real;
       temp. img=img+o2.img;
        return temp;

    
    }
void show(){
    cout<<real<<" + "<<img<<"i";
}


};

int main(){
    opol o1(3,4);
    opol o2(4,6);
    opol o3=o1+o2;
    o3.show();
    return 0;
}