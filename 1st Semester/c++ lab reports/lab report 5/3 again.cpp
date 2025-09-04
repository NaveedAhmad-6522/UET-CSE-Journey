#include <iostream>
using namespace std;

int main(){
	int i=0,size,x[size];
	cout<<"enter size"<<endl;
	cin>>size;
	
	
	cout<<"enter element of array "<<endl;
	do{
		cout<<"value"<<" "<<i+1<<endl;
		cin>>x[i];
		i++;
	}
	while(i<size);
	cout<<"reversed order"<<endl;
 i=size;
	do{
		cout<<"value "<<i--<<" "<<x[i]<<endl;
		i--;
	}
	while(i>0);
return 0;	
}
