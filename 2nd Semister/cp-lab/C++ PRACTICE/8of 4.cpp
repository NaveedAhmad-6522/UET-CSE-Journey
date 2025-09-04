#include <iostream>
using namespace std;
int main(){
	
int pink,blue,white,red,choice,i=1;


cout<<"enter choose their favorite color from the following list"<<endl;

do{
	cout<<"enter your fav color of person"<<i++<<" from the list"<<endl;
	cout<<"enter 1 for red "<<endl;
	cout<<"enter 2 for blue "<<endl;
	cout<<"enter 3 for white "<<endl;
	cout<<"enter 4 for pink "<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			red++;
			break;
			
		case 2:
			white++;
			break;
			
		case 3:
		pink++;
			break;
			
		case 4:
			blue;
			break;
			case -1:
			return 0;
			default:
				cout<<"chose from gaven list"<<endl;
				
	}
	 }
	while(9>8);
	cout<<"********************************"<<endl;
	cout<<" red "<<red;
	cout<<" blue"<<blue;
	cout<<" pink "<<pink;
	cout<<" white "<<white;
	
	


}

