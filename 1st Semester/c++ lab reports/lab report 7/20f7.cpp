#include <iostream>
using namespace std;

int sum(int x=1,int y=2){
	return x+y;
}

int main() {
	int x,y;
	cout<<"enter x and y \n";
	cin>>x>>y;
	if(x==0 && y==0){
		cout<<"both values are zero using default values:\n";
		cout<<"sum is: "<<sum();
	}
	else if(x==0 ){
		cout<<"x value is zero using default value:\n";
		cout<<"sum is: "<<sum(y);
	}
	else if(y==0){
		cout<<"y value is zero using default value:\n";
		cout<<"sum is: "<<sum(x);
	}
	else{
		cout<<"both values are non zero :\n";
		cout<<"sum is: "<<sum(x,y);
	}
	
	
	
}
