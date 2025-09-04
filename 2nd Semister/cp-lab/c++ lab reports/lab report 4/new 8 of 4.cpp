#include <iostream>
using namespace std;
int main(){
	
int pink=0,blue=0,white=0,red=0,choice=0,i=1;


cout<<" choose your favorite color from the following list"<<endl;

do{
	cout<<"chose the fav color of person"<<" "<<i++<<"  from the list"<<endl;
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
			blue++;
			break;
			
		case 3:
	white++;
			break;
			
		case 4:
			pink++;
			break;
			case -1:
			goto here;
			default:
				cout<<"chose from gaven list"<<endl;
				
	}
	 }
	while(9>8);
	here:
	cout<<"********************************"<<endl;
	cout<<" red       "<<red<<endl;
	cout<<" blue      "<<blue<<endl;
	cout<<" pink      "<<pink<<endl;
	cout<<" white     "<<white<<endl;
	
	return 0;
	
	


}

