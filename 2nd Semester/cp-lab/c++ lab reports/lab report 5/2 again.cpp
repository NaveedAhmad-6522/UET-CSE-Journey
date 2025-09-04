#include <iostream>
using namespace std;
int main(){
int i=0,size;
cout<<"enter size of arrays"<<endl;
cin>>size;
int	arr1[size],arr2[size],sum;
cout<<"enter elememnt of first array"<<endl;
do{
	cout<<"value"<<" "<<i+1<<" "<<endl;
	cin>>arr1[i];
	i++;
	
}
while(i<size);
cout<<"enter elememnt of 2nd array"<<endl;
i=size-1;
while(i>=0){
	cout<<"value  "<<i+1<<endl;
	cin>>arr2[i];
	i--;
}

for(i=0;i<size;i++){
	sum=arr1[i]+arr2[i];
	cout<<"sum of "<<i+1<<" "<<sum<<endl;
}
	
	
	
	
	return 0;
}
