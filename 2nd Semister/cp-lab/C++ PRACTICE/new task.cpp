#include <iostream>
using namespace std;

int main(){
	
int Coffee=0,tea=0,coke=0,Orange_Juice=0,choice=0,count=0;
for(int i=0;3<4;i++){
	cout<<"enter your favourate bevrage of person"<<1+count++<<endl;
	
	cout << "1. Coffee" << endl;
        cout << "2. Tea" << endl;
        cout << "3. Coke" << endl;
        cout << "4. Orange Juice" << endl;
        cout << "-1. Exit" << endl;
        cin>>choice;
        switch(choice){
        	case 1:
        		Coffee++;
        		break;
        	case 2:
        		tea++;
        		break;
			case 3:
        	coke++;
        		break;
			case 4:
        	Orange_Juice++;
        		break;
        		case -1:
        			goto start;
				default:
				cout<<"invalide selection"	<<endl;
				
		}
		
	
}
start:

cout << endl << "Survey results:" << endl;
    cout << "******************" << endl;
    cout << "Coffee: " << Coffee << endl;
    cout << "Tea: " << tea << endl;
    cout << "Coke: " << coke << endl;
    cout << "Orange Juice: " << Orange_Juice << endl;
    

    return 0;	
	
	
	
}
