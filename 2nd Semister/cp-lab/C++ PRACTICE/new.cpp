#include <iostream>
#include <string>
using namespace std;


void display(string* arr){
	cout<<arr[0];
	cout<<arr[1];
}

main(){
	string arr[2];
	getline(cin,arr[0]);
		getline(cin,arr[1]);
		
		display(arr);
	
	
	
}
