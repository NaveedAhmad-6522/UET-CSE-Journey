#include <iostream>
using namespace std;
static int binarysearch(int * array,int x,int n){
    if(n==0||x<array[0])return 0;
    if(x>array[n-1])return 0;
    int l,r,m;
    l=array[0];
    r=array[n-1];
    while(r-1>1){
       m=(l+r) /2;
       (x<=array[m]?r:l)=m;


    }
    return r;
    


}
