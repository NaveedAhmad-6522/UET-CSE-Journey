#include <iostream>
using namespace std;
void selection_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int minamum=i;
		for(int j=i+1;j<n;j++){
			if(arr[minamum]>arr[j]){
				minamum=j;
			}
		}
			int temp=arr[i];
			arr[i]=arr[minamum];
			arr[minamum]=temp;
		}
		
		
		
	}
	
	  

int main() {
    int arr[] = {9, 8, 7, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    
    	for(int j=0;j<n;j++){
    		cout<<arr[j]<<" ";
		}
    return 0;
}
