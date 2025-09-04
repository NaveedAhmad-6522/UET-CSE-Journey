#include <iostream>
#include <algorithm>
using namespace std;
void maxmin(int a,int b,int c,int d){
	int maximum=max(a,b,c,d);
	int minimum=min(a,b,c,d);
	cout<<"max" maximum<<endl;
	cout<<"minumum"<<minimum;
	}
main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	maxmin(a,b,c,d);

}
