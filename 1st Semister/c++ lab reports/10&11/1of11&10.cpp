#include <iostream>
#include <string>
using namespace std;

/*A phone number such is (091) 767-8900 can be thought of as having three parts: the area 
code (091), exchange (767) and number 8900. Write a program that uses structure to 
store these 3 parts of a phone number separately. Assume name of the structure is 
‘phone’. Create two objects of type ‘phone’, initialize one object and take the other one 
from the user. Display both numbers. 
Sample Run:
Enter you Area code, exchange, and number: 091 767 8900
My number is (042) 867-4982
Your number is (091) 767-890*/

struct phone{
	string areacode;
	string exchange;
	string number;
	
};

main(){
	phone number1,number2;
	number1.areacode="042";
	number1.exchange="867";
	number1.number="4982";
	
	cout<<"my number is ::"<<number1.areacode<<"  "<<number1.exchange<<"-"<<number1.number<<endl;
	 cout << "Enter your Area code, exchange, and number: ";
	cin>>number2.areacode>>number2.exchange>>number2.number;
	cout<<"your number is :: \n";
	cout<<number2.areacode<<"  "<<number2.exchange<<"-"<<number2.number;
}
