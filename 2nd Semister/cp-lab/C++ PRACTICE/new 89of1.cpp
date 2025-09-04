#include <iostream>
using namespace std;

void fun(int x,int y ,int*sum){
	*sum=x+y;
}
int main(){
	int x,y;
	cout<<"enter x and y: \n";
	cin>>x>>y;
	int result=x+y;
	int*sum=&result;
	fun( x,y,sum);
	cout<<"sum: "<< *sum;
	
}
