#include <iostream>
using namespace std;
class set{
    int* array;
    int size;
    public:
    static int binary_search(int *arr,int x,int size){
        if(x<arr[0])return 0;
          if(x>arr[size-1])return size;
          int l,r,m;
          l=0,r=size-1;
          while(r-1>1){
            m=(r+l)/2;
            (x<arr[m]?r:l)=m;

          }
return r;
    }

    


};