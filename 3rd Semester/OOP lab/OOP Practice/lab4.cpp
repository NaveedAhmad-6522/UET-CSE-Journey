#include "multifile.h"
int main(){
    employee o1("name","cse",9.4,1.3);
    cout<<"displaying the data "<<endl;
    o1.display();
    employee o2=o1;
    cout<<"displaying the data after assigning obj 1 to onj 2 "<<endl;
    o2.display();
    employee o3("asad","civil",700,.21);
    cout<<"after changing all the values in obj 3"<<endl;
    o3.display();
    cout<<"obj 2 data will no change b/c of deep copy"<<endl;
    o2.display();
    return 0;


    

}