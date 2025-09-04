#include <iostream>
using namespace std;

main(){
int x;
int arr[x];

	cout<<"enter the element of array"<<endl;
	cin>>x;
	cout<<"enter element of array"<<endl;
	cout<<"entered values"<<endl;
		
		
	for(int i=1;i<=x;i++){
	cin>>arr[i];
		
	}
	cout<<"reversed order"<<endl;
	
	for(int i=x;i>=1;i--){
		cout<<arr[i]<<endl;
	}
}
