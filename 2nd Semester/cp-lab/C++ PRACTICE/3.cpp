#include <iostream>
using namespace std;
int main(){
int size;
cout<<"enter size of arrays"<<endl;
cin>>size;

int arr1[size];
int arr2[size];
cout<<"enter element of arr1"<<endl;
for(int i=0;i<size;i++)	{
		cout<<"value" <<i+1<<"of array 1"<<endl;
		cin>>arr1[i];
		

	}
	for(int i=0;i<size;i++)	{
		cout<<"value" <<i+1<<"of array 2"<<endl;
		cin>>arr2[i];
		

	}
	int sum;
	
	cout<<"the sum of arrays (element by element)"<<endl;
	for(int i=0;i<size;i++){
		sum=arr1[i]+arr2[i];
		cout<<"sum of "<<i+1<<"elements of arrays is"<<sum<<endl;
		
		
	}
}
