#include <iostream>
#include <algorithm>
using namespace std;
 void minmax(int a ,int b,int c, int d){
 	int minimam=min({a,b,c,d});
 	int maximum=max({a,b,c,d});
 	cout<<"max"<<maximum<<endl;
 	cout<<"minimum"<<minimam<<endl;
 		
 }
 int main(){
 	int a,b,c,d;
 	cin>>a>>b>>c>>d;
minmax(a,b,c,d);
 }
