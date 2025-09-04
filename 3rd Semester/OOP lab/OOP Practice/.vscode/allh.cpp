#include <iostream>
using namespacae std;
class last{
    int *element;
    int size ,capacity;
    static int blocksize=5;
    static int *memmory(int *p1,int n1,int n2){
        int *p2=new int [n2];
        if (p1 !=nullptr){
            for((int i=n1<n2?n1:n2)-1;i>=0;i--){
                p2[i]=p1[i];
                delete[] p1;
            }

        }
        return p2; 
    }

    static binary(int x,int *a,int n){
        int l,r,m;
        if(n==0||x<=a[0]) retutn 0;
        if (x>=a[n-1])return n;
    }

};