#include <iostream>
using namespace std;

void minmax(int a,int b,int c,int d){
int maxnum=a;
int minnum=a;
if(maxnum>b){
	maxnum=b;
}
if(maxnum>c){
	maxnum=c;
}	
	if(maxnum>d){
maxnum=d;
}

if(minnum<b){
	minnum=b;
}
if(minnum<c){
minnum=c;
}	
if(minnum<d){
	minnum=d;
}
cout<<"max"<<" "<<maxnum<<endl;
cout<<"mmin"<<" "<<minnum<<endl;
}

main(){
	int a,b,c,d;
	cout<<"enter a b c d "<<endl;
	cin>>a>>b>>c>>d;
	minmax(a,b,c,d);
}
