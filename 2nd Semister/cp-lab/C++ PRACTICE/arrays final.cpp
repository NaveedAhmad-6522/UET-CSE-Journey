#include <iostream>
using namespace std;
int main(){
	int size;

	cout<<"enter size of array"<<endl;
	cin>>size;
		int*array=new int[size];
	cout<<"enter element of array"<<endl;
	
	for(int i=0;i<size;i++){
		
		cout<<"value"<<" "<<i+1<<endl;
		cin>>array[i];
	}
	
	int max=array[0],min=array[0],sum=0;
	
		for(int i=0;i<size;i++){
		if(max<array[i]){
			max=array[i];
		}
			if(min>array[i]){
			min=array[i];
		}
		sum=sum+array[i];
	}
	double avg;

	avg=sum/size;
	
	cout<<"maximum entered value is"<<" "<<max<<endl;
		cout<<"minumam entered value is"<<" "<<min<<endl;
		cout<<"avg value is"<<" "<<avg<<endl;
	
	
	
	return 0;
}
