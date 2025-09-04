#include <iostream>
using namespace std;

int main(){
cout<<"enter size of array"	<<endl;
int size;
cin>>size;
int array[size];

for(int i=1;i<=size;i++){
	
	cout<<"value "<<i+1<<endl;
	cin>>array[i];
}
	
	
	
	
	cout<<"reversed order";
	
	for(int i=size;i>=0;i--){
		cout<<array[i]<<endl;
		
	}
}
