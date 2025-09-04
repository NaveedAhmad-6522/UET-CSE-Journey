#include <iostream>
using namespace std;
int fact(int num){
	int f=1;
	for(int i=1;i<=num;i++){
		f=f*i;
	}
	return f;

	}
main(){
	
	int num;
	cin>>num;
cout<<fact(num);
		
}
