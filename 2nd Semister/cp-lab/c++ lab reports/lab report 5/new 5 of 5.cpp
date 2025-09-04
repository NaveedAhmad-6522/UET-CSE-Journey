#include<iostream>
using namespace std;
int main(){
	int size,min;
	float max,sum=0;
	cout<<"enter size of array"<<endl;
	cin>>size;
int array[size];
cout<<"enter element of array"<<endl;
for(int i=0;i<size;i++){
cout<<"value "<<i+1<<endl;
cin>>array[i];
		
}
int i;

for(i=0;i<size;i++){
	if(max<array[i]){
		max=array[i];
			}

if(min>array[i]){
		min=array[i];
			}
			sum=sum+array[i];
}

cout<<"max :"<<max<<endl;
cout<<"min :"<<min<<endl;
cout<<"avg :"<<sum/size<<endl;	
	return 0;
	
	
}
