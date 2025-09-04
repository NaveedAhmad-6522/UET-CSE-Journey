#include <iostream>
using namespace std;
class base{
    protected:
    int x,y;
    public:
    base(int xy,int yx):x(xy),y(yx){}

};
class derive:public base{
   protected:
   int z;
   public:
   derive(int xx,int yy,int zz):base(xx,yy),z(yy){}

};
class derive_2:public base{
    protected:
   int s;
   public:
   derive_2(int xx,int yy,int zz):base(xx,yy),s(yy){}

};
class derive_3:virtual public derive,virtual public derive_2{
    protected:
    int m;
    public:
    derive_3(int x,int y,int z ,int mar,int b):derive(x,y,z),derive_2(x,y,mar),m(b){}


};
int main(){
    base o1(2,5);
    derive o2(3,5,345);
    derive_3 o3(3,5,345,4,5);
    return 0;
}
