#include <iostream>
#include <string>
using namespace std;
template<typename T>
T fun(T x, T y){
	return x+y;
}
int main(){
	string data_type;
	cout<<"enter data type only int float double"<<endl;
	getline(cin,data_type);
	if(data_type=="int"){
		int num1,num2;
		cout<<"enter two number \n";
		cin>>num1>>num2;
		cout<<"sum is "<<fun( num1,num2)<<endl;
	}
	else if (data_type == "float") {
        float num1, num2;
         cout << "Enter the first number: ";
       cin >> num1;
      cout << "Enter the second number: ";
        cin >> num2;
        cout << "Result: " <<fun(num1, num2) << endl;
    } else if (data_type == "double") {
        double num1, num2;
              cout << "Enter the first number: ";
       cin >> num1;
      cout << "Enter the second number: ";
        cin >> num2;
        cout << "Result: " << fun(num1, num2) << endl;
    } else {
        cout << "Invalid data type entered." <<endl;
    }

    return 0;
}
