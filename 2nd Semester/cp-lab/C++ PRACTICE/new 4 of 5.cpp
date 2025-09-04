#include <iostream>
using namespace std;
int main(){
	int key,index;
int*array=new int[10];
cout<<"enter values"<<endl;
for(int i=0;i<10;i++){
	cout<<"value"<<i+1<<endl;
	cin>>array[i];
}	
int i;
	
	cout<<"enter a key number"<<endl;
	cin>>key;
for(i=0;i<10;i++){
	if(key==array[i]){
		index=i;
		break;
	}
	
}

if(index==i){
	cout<<key<<" matched with index "<<index<<endl;
	
}
else{
	cout<<key<<" not matched with any of index number";
}
	
	
	
}
