//Write a program to create Simple Calculator using switch case (the calculator must have 
//a loop that it could keep on running and ask the user again for input after showing output 
//from the previous inputs).

#include <iostream>
using namespace std;

main(){
	start:
	
	float a,b,x,y,result;
	char op;
	cout<<"enter first number:"<<endl;
	cin>>a;
	cout<<"input opretor:"<<endl;
	cin>>op;
	cout<<"enter b:"<<endl;
	cin>>b;
	
	while(true){
		
		switch(op){
			
			case '+':
				result=a+b;
				cout<<" sum is:"<<result;
				break;
				case '-':
				result=a-b;
				cout<<" sub is:"<<result;
				break;
				case '*':
				result=a*b;
				cout<<" preduct is:"<<result;
				break;
				case '/':
            if (b == 0) {
               cout << "Error: Cannot divide by zero" << endl;
               break;
            }
            result = a / b;
            cout <<a << " / " <<b << " = " <<  result << endl;
            break;
				
				
				default:
					cout<<"syntax error:"<<endl;
					
		}
		cout<<endl;
		cout<<endl;
		
		goto start;
		
			
	
		}
		
	}

