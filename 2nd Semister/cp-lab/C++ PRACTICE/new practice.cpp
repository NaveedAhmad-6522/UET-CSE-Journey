#include <iostream>
using namespace std;
 int main(){
int num1,num2;
char op;
cout<<"enter first number"<<endl;
cin>>num1;
cout<<"enter opreter"<<endl;
cin>>op;
cout<<"enter 2nd number"<<endl;
cin>>num2;
switch(op){
case '+':
	cout<<"sum is: "<<num1+num2;
	break;
	case '-':
	cout<<"sub is: "<<num1-num2;
	break;
	case '*':
	cout<<"product is: "<<num1*num2;
	break;
	case '/':
		if(num2==0){
			cout<<"denumerator coulkd't be zero";
			return 0;
		}
		
	cout<<"division is: "<<num1/num2;
	break;
	default:
		cout<<"i'm still learning ";
		
	
	
	
	
	
}
return 0;
	
	
	
	
	
	
}
