#include <iostream>
using namespace std;

int main(){
	int num ;
cout<<"enter a number"	;
cin>>num;
if(num>10 || num<1){
	cout<<"invalide number"<<endl;
	return 0;
}
else{
	for(int i=0;i<num;i++){
		cout<<"*";
	}
}
	
	
	
	
}
