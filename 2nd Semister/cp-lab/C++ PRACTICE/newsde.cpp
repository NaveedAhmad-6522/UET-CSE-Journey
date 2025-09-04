/*


#include <iostream>
#include <string>
using namespace std;
template<typename T>
T  fun(T x,T y){
 return x+y;
 }
 
 
 main(){
 	string data;
 	getline(cin,data);
 	if(data=="float"){
 		float x,y;
 		cin>>x>>y;
 		cout<<fun(x,y);
 		
	 }
	 else if(data=="int"){
 		int x,y;
 		cin>>x>>y;
 		cout<<fun(x,y);
 		
	 }
 }
 Calculate the sum of odd natural numbers 1+3+5+7+……………. + n using Recursion. 
Take n as input from user
 */
 
 
 #include <iostream>
#include <string>
using namespace std;
 
int myfun(int n){
	if (n==0)
	return 1;
	else
	return n*myfun(n-1) ;
}
main(){

	cout<<myfun(4);
}

