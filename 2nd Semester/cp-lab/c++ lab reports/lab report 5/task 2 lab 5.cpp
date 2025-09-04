#include <iostream>
using namespace std;

main(){
	int x;
int arr1[x]	,arr2[x];
cout<<"enter number of intger in arrays"<<endl;
cin>>x;

for(int i=0;i<x;+i++){
	cout<<"enter element of arr1"<<endl;
	cout<<"element "<<i+1<<endl;
	cin>>arr1[i];
	
}

for(int i=0;i<x;+i++){
	cout<<"enter element of arr2"<<endl;
	cout<<"element "<<i+1<<endl;
	cin>>arr2[i];
	
}
for(int i=0;i<x;+i++){
	int sum[i];
	sum[i]=arr1[i]+arr2[i];
	cout<<"sum of "<<i+1<<"elements of arr1 & arr2 is:"<<sum[i];
}
	
	
}
