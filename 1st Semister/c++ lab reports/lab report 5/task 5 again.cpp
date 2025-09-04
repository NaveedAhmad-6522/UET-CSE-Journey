#include <iostream>
using namespace std;

main(){
	
	int size,i=0 ;
	cout<<"enter size of array"<<endl;
	cin>>size;
	int x[size]; 
	
	cout<<"enter integer of givn size"<<endl;
	while(i<size){
		
	
	cin>>x[i];
	i++;
	}
	int max=x[0],min=x[0],sum=0;
	for(int i=0;i<size;i++){
		if(max<x[i]){
			max=x[i];
	
		}
			if(min>x[i]){
			min=x[i];
	
		}
		sum=sum+x[i];
	
		
		
	}
	cout<<"maximum"<<max<<endl;
	cout<<"minumam"<<min<<endl;
	cout<<"avrage"<<sum/size<<endl;
}
