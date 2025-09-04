#include <iostream>
using namespace std;

void fun(int*x,int*y,int*arr){
	arr[4] = arr[*x] + arr[*y];
}
main(){
	int arr[5];
	int*ptr=arr;
	cout<<"enter first four values: \n";
	for(int i=0;i<4;i++){
		cin>>*(ptr+1);
	}
	int num1,num2;
	cout<<"enter values \n";
	cin>>num1>>num2;
	
	  fun(&num1, &num2, ptr);

    cout << "Updated fifth index of the array: " << arr[4] << endl;

    return 0;
}
	

