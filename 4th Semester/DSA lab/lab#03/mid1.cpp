#include <iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
    int first=0;
    int last=n-1;
    while(first<=last){
        int mid=first+(last-first)/2;
        if(arr[mid]==key)return  mid;
        else if (arr[mid]>key){
            last=mid-1;
        }
        else{
            first=mid+1;
        }
    }


return -1;
}

int main(){
int arr[]={1,2,3,4,5,6};
int size=6;
int target=6;
   cout<< binarysearch(arr,size,target);

}