#include <iostream>
using namespace std;
/*Write a program which calculates the average of an array of 5 elements (initialize the values 
of the array during declaration) the average should be calculated in a function called 
average(), this function will have a pointer parameter (array must be passed here) and an 
integer parameter (which is the size of array) i.e., average(int *arr , int size)*/
void average(int*arr,int size=5){
	int sum=0;
	
	for (int i=0;i<size;i++){
		sum=sum+arr[i];
	
	}
	float avg=static_cast<float>(sum)/size;
	cout<<"average = "<<avg;
}


main(){
	int arr[5]={2,4,5,6,7};
	int size=5;
	average(arr,size);
}
