#include <iostream>
using namespace std;

main(){
	int arr[5],temp;
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	cout<<"entered order \n";
		for(int i=0;i<5;i++){
	cout<<arr[i]<<" ";
	}
	
	cout<<"sorting:";
		for(int i=0;i<5;i++){
			for(int j=0;j<4;j++){
				if(arr[j]>arr[j+1]){
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
	}
	}
		for(int j=0;j<5;j++){
		cout<<arr[j]<<" ";
	}
}
