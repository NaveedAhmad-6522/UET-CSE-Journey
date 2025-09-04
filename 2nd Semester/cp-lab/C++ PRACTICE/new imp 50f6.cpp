#include <iostream>
#include <cmath>
using namespace std;
 int deter(int a,int b,int c ){
 	

 	int d=b*b-4*a*c;
 	return d;
 	
 	
 }
 void root(int a,int b,int c){
 	int d=deter(a,b,c);
 	float r1,r2;
 	if(d>0){
 		
 		r1 = (-b + sqrt(d)) / (2*a) ;
		r2 = (-b - sqrt(d)) /(2*a);
		cout<<"roots are real and different\n";
		cout << "Root 1 = " << r1 << endl;
        cout << "Root 2 = " << r2 << endl;
	 }
	else if(d==0){
	   r1 = r2 = -b/(2*a);
	   cout << "The roots are real and equal:" << endl;
        cout << "Root 1 = Root 2 = " << r1 << endl;
	   }
else  {
float realroot= (-b/(2*a));
float imgroot =sqrt(-d)/(2*a);
cout << "The roots are complex and different:" << endl;
        cout << "Root 1 = " << realroot << " + " << imgroot << "i" << endl;
        cout << "Root 2 = " << realroot << " - " << imgroot << "i" << endl;
    }
 }
 int main(){
 	int a,b,c,d;
 	cin>>a>>b>>c;
 	root(a,b,c);
 }
