#include<iostream>
using namespace std;

main(){
	int x[10],key,index;
	cout<<"enter array"<<endl;
	for(int i=0;i<10;i++){
		cout<<"value"<<" "<<i+1<<endl;
		cin>>x[i];
	}
	cout<<"enter key num"<<endl;
	cin>>key;
		for(int i=0;i<10;i++){
			if(key==x[i]){
				index=i;
				break;
				
			}
			if(key!=x[i]){
				index=-1;
				break;
			}
			
			
		}
		if(index !=-1){
			cout<<key<<" is matched with index  "<<index<<endl;
			
		}
		else{
			cout<<"not matched"<<endl;
		}
	
	
	}sss
