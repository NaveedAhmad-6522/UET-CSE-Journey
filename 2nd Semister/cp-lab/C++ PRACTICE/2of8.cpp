#include <iostream>
#include <string>
using namespace std;
void display(string* array){
	
cout << "Name: " << array[0] <<endl;
cout << "Registration Number: " << array[1] <<endl;
}
main(){
	string array[2];
	cin>>array[0];
	cin>>array[1];
	display(array);
}

