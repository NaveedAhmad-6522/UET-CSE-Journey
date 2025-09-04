#include<iostream>
using namespace std;
class vct{
    int magnituid ;
    int direction;
    public:
    vct():magnituid(0),direction(0){}
    vct(int m,int d):magnituid(m),direction(d){}
vct operator+(const vct& o2)const{
   vct twm;
    twm.magnituid=magnituid+o2.magnituid;
    twm.direction=direction+o2.direction;
    return twm;
}
void dsp(){
    cout<<"magnitiuied: "<< magnituid<<" iraction : "<<direction<<endl;
}


};
int main(){
    vct o1(3,4);
    vct o2(4,3);
    vct sum;
  sum=  o1+o2;
sum.dsp();

    return 0;
}