#include <iostream>
using namespace std;
class set{
    int * elements;
    int size;
    int capacity;
    int block_size;
    public:
    set() : elements(nullptr), size(0), capacity(0) {}
    static int* memoryspace(int* p0, int n0, int n1) {
        int* p1 = new int[n1];
        if (p0 != nullptr) {
            for (int i = (n0 < n1 ? n0 : n1) - 1; i >= 0; --i) {
                
                p1[i] = p0[i];
            }
            delete[] p0;
        }
        return p1;
    }

    static int binary_search(int new_elememnt ,int * array,int n){
        int left,right,mid;
        if(new_elememnt<array[0])return 0;
        if(new_elememnt>array[n-1])return n;
        left=0;
        right=n-1;
        while(right-1>1){
          (  (array[mid]<=new_elememnt)?right:left)=mid;
          
        }

return right;
    }
    set &  operator+=(x){
        
    }

};