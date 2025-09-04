#include <iostream>
using namespace std;

main(){
int i=0,x[12];
cout<<"values of array"<<endl;
while(i<12)	{
	cout<<"value "<<i+1<<endl;
	cin>>x[i];
	i++;
}

for(i=0;i<12;i++){
	cout<<"value "<<i+1<<" "<<x[i];
	if((i+1)%3==0){
		cout<<endl;
	}
}



	
}
