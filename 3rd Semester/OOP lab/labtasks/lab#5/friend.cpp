#include <iostream>
#include <string>
using namespace std;
class dept;// farward decleration
class student{
    string id;
    string name;
    public:
student(string i,string n):id(i),name(n){}
void show(){
    cout<<id<<endl<<name<<endl;}

    //friend fun
    friend void assignDpt(student &s ,dept &p ,string deptname);
};
class dept{
    string deptname;
    public:
    dept(string dn):deptname(dn){}
    void show (){
        cout<<"show dept::\n "<<deptname<<endl;

    }
    friend void assignDpt(student &s ,dept &p ,string deptname);

    };
 void assignDpt(student &s ,dept &p ,string deptname){
s.name="Dauad shah";
p.deptname="pashto departement";

}
int main(){
student s1("007","mujahid");
dept d1("DCSE");
    s1.show();
    d1.show();
     assignDpt(s1,d1,"pushto departement ");
     s1.show();
     d1.show();



    return 0;

}

