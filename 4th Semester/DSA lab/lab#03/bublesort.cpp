#include <iostream>
using namespace std;
int bubblesort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int size=9;
     bubblesort( arr, size);
     for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";

     }
return 0;
}