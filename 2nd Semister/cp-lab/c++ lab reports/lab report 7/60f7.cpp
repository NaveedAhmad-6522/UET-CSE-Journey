#include <iostream>
using namespace std;
	double fun(double n){
		if(n==0){
			return 1;
		}
		else{
			return n*fun(n-1);
	
		}
	}
int main(){
double n;
	cout<<"enter a number \n";
	cin>>n;
	if(n<0){
		cout<<"number must be positive \n";
		return 0;
	}
	cout<<"factorial of "<<n<<"! is "<<fun(n)<<endl;
	return 0;
	
}
