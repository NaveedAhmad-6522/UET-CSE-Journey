#include <iostream>
using namespace std;

 int main(){
	 float unit_consumed,charges,surcharge;
double id;
	
	cout<<"enter your id"<<endl;
	cin>>id;
	cout<<"enter unit consumed"<<endl;
	cin>>unit_consumed;
	
	if(unit_consumed<=199){
	
		charges=unit_consumed*1.20;
		}
		else if(unit_consumed>=199 && unit_consumed<400) {
		
		charges=unit_consumed*1.50;
		}
			else if(unit_consumed>=400 && unit_consumed<600) {
			
		charges=unit_consumed*1.80;
		}
			else  {
		charges=unit_consumed*2;
		}
		
		if(charges>400){
			surcharge=charges*0.15;
		}
		
		
		
		cout<<"customer id:"<<" "<<id<<endl;
		cout<<"unit_consumed:"<<" "<<unit_consumed<<endl;
	    cout << "Amount Charges @Rs. " <<charges<< " per unit: " << charges/unit_consumed << endl;
		cout<<"surcharge " <<surcharge<<endl;
		cout<<"net amount :"<<charges+surcharge<<endl;
		
		return 0;
	
	
	
}
