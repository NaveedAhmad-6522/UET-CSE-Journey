#include <iostream>
using namespace std;

main()
{
	int month;
	int a=30,b=28, c=31,d=29;
	
	cout<<"enter month(1-12):";
	cin>>month;
	
	switch(month){
		case 1:
			cout<<"januyrey: number of days:"<<c<<endl;
			break;
		case 2:
			cout<<"fab: number of days:"<<b<<endl;
				break;
		case 3:
			cout<<"march: number of days:"<<c<<endl;
				break;
		case 4:
			cout<<"april: number of days:"<<c<<endl;
				break;
		case 5:
			cout<<"may: number of days:"<<a<<endl;
				break;
		case 6:
			cout<<"june: number of days:"<<c<<endl;
				break;
		case 7:
			cout<<"july: number of days:"<<a<<endl;
				break;
			
		case 8:
			
			cout<<"agust: number of days:"<<a<<endl;
				break;
		case 9:
			cout<<"sept: number of days:"<<a<<endl;
				break;
		case 10:
			cout<<"OCT: number of days:"<<c<<endl;
				break;
		case 11:
			cout<<"nov: number of days:"<<a<<endl;
				break;
		case 12:
			cout<<"dec: number of days:"<<a<<endl;
				break;
				default:
					cout<<"i am still learning:";
	}
	return 0;
}
