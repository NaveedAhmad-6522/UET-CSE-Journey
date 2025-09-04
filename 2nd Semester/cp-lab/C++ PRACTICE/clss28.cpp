#include <iostream>
using namespace std;


/*void add(int*x,int*y){
	*x=*x+*y;
}*/
int add(int x,int y){
	return x+y;
}
int sub(int x,int y){
	return x-y;
}
int oper(int x,int y,int(*fun)(int,int){

	int sum=(*fun)(x,y);
	return sum;
}
int main(){
//A=NUIIPTR;
/*int arr[5]={5,4,3,2,1};
cout<<arr[1];
int*p;
p=arr;
cout<<arr<<endl;
cout<<*p<<endl;
*p=50;
p++;
*p=30;
cout<<arr[1]<<endl;
p=&arr[2];
*p=30;
p=arr+3;
*p=10;
cout<<arr[3]<<endl;

p=arr;
*(p+4)=20;
cout<<*p<<endl;

for(int i=0;i<5;i++){
	*(p+1);
	cout<<*(p+1)<<endl;


int x=5,y=10;
add(&x,&y);
cout<<x<<endl;*/
cout<<oper(4,4,add);
}
