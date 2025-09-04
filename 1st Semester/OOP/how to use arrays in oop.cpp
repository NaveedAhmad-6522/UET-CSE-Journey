#include <iostream>
#include <vector>
using namespace std ;
class shop{
	int counter;
    vector<int> itemid;
    vector<int> itemprice;
	public:
		void getNo();
		void setprice();
		void displayprice();
};
void shop::getNo(){
	cout<<"enter number of items you want to stores \n";
	cin>>counter;
}
void shop::setprice(){
	  itemid.resize(counter);
    itemprice.resize(counter);
	for (int i=0;i<counter;i++){
		cout<<"enter id of item :"<<i+1<<endl;
		cin>>itemid[i];
		cout<<"enter price of item :"<<i+1<<endl;
		cin>>itemprice[i];
	}
}
void shop::displayprice(){
	for (int i=0;i<counter;i++){
		cout<<"item ID :"<<i+1<<itemid[i]<<endl;
		cout<<"item price :"<<itemprice[i]<<endl;
}
}
int main(){
	shop myshop;
	myshop.getNo();
	myshop.setprice();
	myshop.displayprice();
	return 0;
}


