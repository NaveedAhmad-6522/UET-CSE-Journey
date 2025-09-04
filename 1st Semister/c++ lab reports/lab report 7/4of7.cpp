#include <iostream>
using namespace std;
int sum(int n){
	
	if(n<=0){
		return 0;
	}
	else{
	
	return (2*n-1)+sum(n-1)	;
	}
	
}
int main(){
	int n;
	cout<<"enter n \n";
	cin>>n;
	cout<<"sum of n natural odd num is \n";
	cout<<sum(n);
}
