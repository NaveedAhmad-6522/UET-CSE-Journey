#include <iostream>
using namespace std;

main()
{
	int a,b,c;

	cout<<"enter the three number:";
	cin>>a>>b>>c;
	
	if(a>=b && a>=c){
		cout<<"the laregest number is:"<<a<<endl;
		}
		
else if(b>=a && b>=c){
	cout<<"the laregest number is:"<<b<<endl;
	}
	
	else{

		cout<<"the laregest number is:"<<c<<endl;
			}
		
		return 0;
	}

