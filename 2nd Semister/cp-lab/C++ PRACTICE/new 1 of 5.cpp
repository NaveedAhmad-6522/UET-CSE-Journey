#include <iostream>
using namespace std;
main(){
int array[12];
cout<<"enter the numbers"<<endl;
for(int i=0;i<12;i++){
	cout<<i+1<<"  number"<<endl;
	cin>>array[i];

}
for(int i=0;i<12;i++){
	
		cout<<"value:  "<<i+1<<" "<<array[i];
	if((i+1)%3==0){
		cout<<endl;
	}
	
}
}
