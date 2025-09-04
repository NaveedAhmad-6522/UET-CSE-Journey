#include <iostream>
using namespace std;


int main(){
int size;
cout<<"enter the size of arrays"<<endl;
cin>>size;
int arr1[size],arr2[size];

cout<<"enter elemnt of arrays"<<endl;


cout<<"arr1"<<endl;
for(int i=0;i<size;i++){
	
	cout<<i+1<<" value of arr1"<<endl;
	cin>>arr1[i];
}

cout<<"arr1"<<endl;
for(int i=0;i<size;i++){
	
	cout<<i+1<<" value of arr2"<<endl;
	cin>>arr2[i];
}
	
	cout<<"now to find sum off arrays element by7 element "<<endl;
	int sum=0;
	
	for(int i=0;i<size;i++){
		
		sum=arr1[i]+arr2[i];
		cout<<sum<<endl;
		
	

}
	
	
}

