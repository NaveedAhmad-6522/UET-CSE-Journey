#include <iostream>
using namespace std;
int fact(int num){
	int f=1;
	for(int i=0;i<num;i++){
		f=f*num;
	}
	return f;
	cout<<f;
	}
main(){
	
	int num;
	cin>>num;
	fact(num);
	
}
