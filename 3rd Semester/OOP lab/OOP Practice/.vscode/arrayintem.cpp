#include <iostream>
using namespace std;
template <class T=float,int size=6>
class tem_array{
    T temarray[size];
    public:
    tem_array(){}
    T& operator[](int i1){
        if(i1<size)return temarray[i1];
        else
        throw("error! index must be less than size");
    }
     void display() const {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
           cout << temarray[i] << " ";
        }
       cout <<endl;
    }


};
int main(){
    tem_array<>floatarray;
    tem_array<int,4> Array;
    tem_array<double,5> doubleArray;
        tem_array<string,6> stringArray;

    
for(int i=0;i<4;i++){
        Array[i]=i;
    }   
    for(size_t i=0;i<5;i++){
        doubleArray[i]=i*2.3;
    } 
    for(size_t i=0;i<6;i++){
        floatarray[i]=i*2.3;
    }  
     for(size_t i=0;i<6;i++){
        stringArray[i]=i*2.3;
    }  
   doubleArray.display();
   Array.display();
   stringArray.display();
   floatarray.display();
    return 0;
}
