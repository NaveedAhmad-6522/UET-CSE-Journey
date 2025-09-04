#include <iostream>
using namespace std;
//a)	Write a recursive implementation of Factorial.

int recursive_implementation_of_Factorial(int number){
    if(number==0)return 1;
    else{
        return number*recursive_implementation_of_Factorial(number-1);
    }
}
int main(){
    int number;
    cout<<"enter a positive number:"<<endl;
    cin>>number;
    cout<<"Factorial of "<<number<<" is :"<<recursive_implementation_of_Factorial(number);
    return 0;
}


/*b)	Write an iterative (i.e. use any of the looping constructs (for, do-while, while) to accomplish the task) implementation of Factorial.
void Factorial(){
    int number;
    cout<<"enter a number "<<endl;
    cin>>number;
    int fact=1;
    cout<<number;
    do{
        fact=number*fact;
        number--;


    }while(number>0);
    cout<<"! ="<<fact<<endl;
}
int main(){
    Factorial();
    return 0;
}*/