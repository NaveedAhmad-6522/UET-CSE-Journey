#include <iostream>
using namespace std;

main()
{
	int weekday;
	
	cout<<"enter week day(1-7):";
	cin>>weekday;
	
	switch(weekday)
	{
	case 1:
	cout<<"monday"	<<endl;
	break;
	case 2:
	cout<<"tuesday"	<<endl;
	break;
	case 3:
	cout<<"wednesday"	<<endl;
	break;
	case 4:
	cout<<"thursday"	<<endl;
	break;
	case 5:
	cout<<"friday"	<<endl;
	break;
	case 6:
	cout<<"saturday"	<<endl;
	break;
	case 7:
	cout<<"sunday"	<<endl;
	break;
	
	default:
	cout<<"error:i am still learning"<<endl;
	
		
	}
	return 0;
}
