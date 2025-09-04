#include <iostream>
using namespace std;

struct genre{
	string type;

};
struct  music{
int relaseyear;
string albumname;
genre g;


}a;
void display(music a){
	
	cout<<a.relaseyear<<endl;
	cout<<a.albumname<<endl;
	cout<<a.g.type<<endl;
	
}
 
main(){
music n[3];
 
for(int i=0;i<3;i++){
	cout<<"enter music data "<<i<<endl;
	cout<<" relaseyearyear?"<<endl;
	cin>>n[i].relaseyear;
	cout<<"genre"<<endl;
	cin>>n[i].g.type;

}
for(int i=0;i<3;i++){
	display(n[i]);
}
}

