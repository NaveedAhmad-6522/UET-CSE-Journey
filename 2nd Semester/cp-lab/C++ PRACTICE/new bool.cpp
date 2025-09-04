#include <iostream>
using namespace std;
bool prime(int num){
	if(num<=1){
		return false;
	}
	for(int i=2;i<=num/2;i++)
	if(num%i==0){
		return false;
	}
		 return true;
	
}
int main(){
	int num;
	cin>>num;
	if(prime(num)){
		cout<<num<<" is prime \n";
		}
		else{
		
		cout<<num<<"  is not prime \n";
	}
	
}
