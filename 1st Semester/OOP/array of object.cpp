#include <iostream>
using namespace std;
/*array of object objective:
using this we can call a single function qgain and again very easyly.
*/
class employee{
	int id;
	int salary;
	public:
		void setdata(){
			cout<<"enter id of employee"<<endl;
			cin>>id;
			cout<<"enter salary of employee: "<<id<<endl;
			cin>>salary;
		}
		void getdata(){
			cout<<"id of this employee "<<id<<endl;
		}
};
main(){
	int n ;
	cout<<"enter n "; 
	cin>>n;
	employee arr[n];
	for(int i=0;i<n;i++){
		arr[i].setdata();
		arr[i].getdata(); 
	}
}
