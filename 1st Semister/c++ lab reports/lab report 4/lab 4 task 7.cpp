#include <iostream>

using namespace std;

int main() {
    
    string name = "naveed ahmad";
    string reg_num = "22pwcse2165";
    
    
    for (int i = 1; i <= 10; i++) {
        
        if (i == 5) {
        	cout<<endl;
        		cout<<endl;
            cout << "Mid of loop" << endl;
            	cout<<endl;
            	cout<<endl;
            continue;
        }
        
        
        cout << name <<endl;
		cout<< reg_num << endl;
    }
    
    return 0;
}

