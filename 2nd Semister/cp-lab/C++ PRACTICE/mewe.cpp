#include <iostream>
using namespace std;

main(){
	int x,y,sum;
	cin>>x>>y;
	int*ptr=&sum;
	*ptr=x+y;
	cout<<*ptr;
}
