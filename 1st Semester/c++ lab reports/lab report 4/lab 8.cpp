#include <iostream>
using namespace std;

main(){

int x[10];
int key;
cout<<"enter element of array"<<endl;

for(int i=0;i<10;i++){
	cout<<"value"<<"  "<<i+1<<endl;
	cin>>x[i];
	
	
}
cout<<"enter key ";
	cin>>key;
	for(int i=0;i<10;i++){
		
		if(key==x[i]){
			cout<<x[i]<<" matched of index"<<i<<endl;
			return 0;
		}
		else{
			cout<<"not";
			return 0;
		}
	}



}
