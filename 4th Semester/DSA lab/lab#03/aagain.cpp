User
#include <iostream>
using namespace std;
int selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minimam=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minimam]){
                minimam=j;
            }

        }
        if(minimam!=i){
            swap(arr,minimam,i);
        }
    }
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int size=9;
     selection( arr, size);
     for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";

     }
return 0;

}
