#include <iostream>
using namespace std;

struct phone {
	string areacode;
	string exchange;
	string number;
};
int main(){
phone	number1,number2;
	
	number1.areacode="091";
	number1.exchange="767";
	number1.number="8900";
	
	cout<<"enter the code for 2nd object \n";
	cin>>number2.areacode;
	cout<<"enter the exchange for 2nd object \n";
	cin>>number2.exchange;
		cout<<"enter the number for 2nd object \n";
	cin>>number2.number;
	cout << "Phone number 1: (" << number1.areacode << ") " << number1.exchange << "-" << number1.number << endl;
    cout << "Phone number 2: (" << number2.areacode << ") " << number2.exchange << "-" << number2.number << endl;

    return 0;
	
	
}
