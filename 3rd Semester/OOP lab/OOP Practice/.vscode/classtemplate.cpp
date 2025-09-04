#include <iostream>
#include <string>
using namespace std;
template <class T>
class box{
    T value;
    public:
    box(T v):value(v){}
    T return_V(){
        return value;
    }


};
int main(){
    box<int> o1(32);
     box<double> o2(3.32);
      box<string> o3("naveed ahmad");
     cout<< o1.return_V()<<endl;
    cout<<  o2.return_V()<<endl;
     cout<< o3.return_V()<<endl; 
     box<> o1(32);
      return 0;

}