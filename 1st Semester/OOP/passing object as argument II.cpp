#include <iostream>
using namespace std;
class time{
	int hours;
	int min;
	public:
		void setdata(){
			cout<<"enter hours \n";
			cin>>hours;
			cout<<"enter mintues \n";
			cin>>min;
			
		}
		
	
		void displaystandard(time o1,time o2){
			hours=(o1.min+o2.min)/60;
			min=(o1.min+o2.min)%60;
			hours=hours+(o1.hours+o2.hours);
			
		}
			void displaydata(){
			cout<<"you entered the data\n";
			cout<<"hours :"<<hours<<endl;
			cout<<"mintues :"<<min<<endl;
		
			
		}
	
};
int main(){
	time c1,c2,c3;
	c1.setdata();
	c1.displaydata();
	
	c2.setdata();
	c2.displaydata();
	
	c3.displaystandard(c1,c2);
	c3.displaydata();
	return 0;
}
