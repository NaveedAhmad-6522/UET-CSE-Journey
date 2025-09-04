#include <iostream>
#include <vector>
using namespace std;
class employee{
	int id;
	static int count;
	public:
		void getdata(){
			cout<<"enter id"<<endl;
			cin>>id;
			count++;
		}
	void setdata(){
		cout<<"the id of employee " <<id<<"and this is employee number"<<count<<endl;
	}
	static void getcount(){
		cout<<"the value of count is"<<count<<endl;
	}

};
int employee::count=2000;
main(){
	employee naveed,basit,zarar;
	 
	naveed.getdata();
	naveed.setdata();
	employee::getcount();
	
	cout<<endl;
	
     basit.getdata();
	basit.setdata();
		employee::getcount();
		cout<<endl;
	zarar.getdata();
	zarar.setdata();
		employee::getcount();
			cout<<endl;
}
