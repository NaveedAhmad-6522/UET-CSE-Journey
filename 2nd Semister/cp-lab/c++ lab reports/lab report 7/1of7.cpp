#include <iostream>
using namespace std;
void fun(int num){
	if (num<=0){
		return;
	}
	else{
	
	cout<<"your reg id is "<<"22pwcse2165 \n";
	cout<<"your name is  "<<"naveed ahmad  \n";
	fun(num-1);
}
}

 main(){
 	fun(10);
 	
	
}
