#include <iostream>
using namespace std;
int main(){
	int num;
cout<<"enter a number:"<<endl;
cin>>num;

cout<<"table of "<<num<<" is"<<endl;

for(int i=0;i<=num;i++){
	
	cout<<num<<"X"<<i+1<<"="<<num*(i+1)<<endl;
}
return 0;

}
