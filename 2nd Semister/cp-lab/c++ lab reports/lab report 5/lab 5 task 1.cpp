#include <iostream> 
using namespace std;

main(){

int x[12];
cout<<"enter values"<<endl;
for(int i=0;i<=11;i++){
	cout<<"value "<<i+1<<" :";
	cin>>x[i];
}
for(int i=0;i<=11;i++)	{
	cout<<"value"<<i+1<<" :"<<x[i]<<"    ";
	if((i+1)%3==0){
		cout<<endl;
	}
}
	
}
