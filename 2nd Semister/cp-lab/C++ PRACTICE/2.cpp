#include <iostream>
using namespace std;
int main(){
	
int size;
int*arr=new int[size];
cout<<"enter the size of array"	<<endl;
cin>>size;
cout<<"enter elements of array"<<endl;
for(int i=0;i<size;i++){
	cin>>arr[i];
}
int max,min,sum=0;
for(int i=0;i<size;i++){
		if(min>arr[i]){
			min=arr[i];
	    	cout<<endl;
		}
		if(max<arr[i]){
			max=arr[i];
			cout<<endl;
		}
		sum=sum+arr[i];
		
		
		
	} 
cout<<"maximum"<<max<<endl;
cout<<"minumam"<<min<<endl;
cout<<"avg"<<sum/size<<endl;
return 0;


	
}
