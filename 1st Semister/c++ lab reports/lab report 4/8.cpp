#include <iostream>
using namespace std;

main(){
	int red,green,blue,white,choice;
	for(int i=0;9<77;i++){
		

	cout<<"enter fav color of person"<<"1"<<endl;
	
	
	cout << "1 for Coffee" << endl;
        cout << "2 for Tea" << endl;
        cout << "3 Coke" << endl;
        cout << "4  Orange Juice" << endl;
        cout << "-1  Exit" << endl;

        cin >> choice;
	
	switch(choice){
		case 1:
        		blue++;
        		break;
        	case 2:
        		red++;
        		break;
			case 3:
        	green++;
        		break;
			case 4:
        white++;
        		break;
        		case -1:
        		goto a;
				default:
				cout<<"invalide selection"	<<endl;
				
		
	
}
}
a:

cout << endl << "Survey results:" << endl;
    cout << "******************" << endl;
    cout << "blue: " << blue << endl;
    cout << "red: " << red << endl;
    cout << "green: " << green<< endl;
    cout << "white: " << white << endl;
    

    return 0;
		
		
	}
	

