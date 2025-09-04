#include <iostream>
using namespace std;

main()
{
	

int size;
cout<<"enter the size of array:"<<endl;
cin>>size;

int*x=new int[size];
cout<<size<<endl;
cout<<"value for each element in array"<<endl;
for(int i=0;i<size;i++)
	{
		cout<<"value for"<<i+1<<" =";
		cin>>x[i];
	}
	float min,max,sum=0;
	
 for(int i=0;i<size;i++){
		if(min>x[i]){
			min=x[i];
			
	    	cout<<endl;
		}
		if(max<x[i]){
			max=x[i];
			cout<<endl;
		}
		sum=sum+x[i];
		
		
		
	} 
	float avg=sum/size;
	cout<<"minimam value "<<min<<endl;
		cout<<"maximum value "<<max<<endl;
			cout<<"avg value "<<avg<<endl;
		}
