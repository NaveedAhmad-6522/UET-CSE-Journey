#include <iostream>
using namespace std;

main(){
int arr[10];
int num,index;

cout<<"enter elements of array "<<endl;
for(int i=0;i<10;i++){
	cin>>arr[i];
}
cout<<"enter a key number"<<endl;
cin>>num;
for(int i=0;i<10;i++){
if(num==arr[i]){
	index=i;
	break;
}
	
	
	}
	if(index !=-1){
		cout<<num<<" matched with index "<<index<<endl;
		
	}
	else{
		cout<<num<<"not matched with any index! ";
	}
	

return 0;
}

