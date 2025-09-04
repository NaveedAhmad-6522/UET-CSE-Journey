#include <iostream>
using namespace std;



int minmax(int num_1,int num_2,int num_3,int num_4){
	if(num_1>num_2 && num_1>num_3 && num_1>num_4 ){
		return num_1;
		
	}
	if(num_2>num_1 && num_2>num_3 && num_2>num_4 ){
		return num_2;
		
	}
	if(num_3>num_1 && num_3>num_2 && num_3>num_4 ){
		return num_3;
		
	}
if(num_4>num_1 && num_4>num_3 && num_4>num_2){
		return num_4;
		
		
	}
		
}
int minmax1(int num_1,int num_2,int num_3,int num_4){
	if(num_1<num_2 && num_1<num_3 && num_1<num_4 ){
		return num_1;
		
	}
	if(num_2<num_1 && num_2<num_3 && num_2<num_4 ){
		return num_2;
		
	}
	if(num_3<num_1 && num_3<num_2 && num_3<num_4 ){
		return num_3;
		
	}
if(num_4<num_1 && num_4<num_3 && num_4<num_2){
		return num_4;
		
		
	}
}
int main(){
	int a,b,c,d;
	cout<<"enter four numbers"<<endl;
	cin>>a>>b>>c>>d;
int max=minmax(a,b,c,d)	;
cout<<"maximum number is: "<<max<<endl;
	int min=minmax1(a,b,c,d);
	cout<<"minuman: "<<min<<endl;
	
}
