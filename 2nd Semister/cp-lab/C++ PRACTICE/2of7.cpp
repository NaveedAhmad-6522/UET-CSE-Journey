#include <iostream>
using namespace std;

int sum(int x=3,  int y=4) {
	
    return x+ y;
}

int main() {
    int a, b;
    cout << "Enter two values: ";
    cin >> a >> b;

    if (a == 0 && b == 0) {
        cout << "Both values are zero. using default values" << endl;
        cout<<"sum is "<<sum(3,4);
    }
    else if (a == 0) {
        cout << "First value is zero. Using default value of 3." << endl;
        cout << "Sum: " << sum(3, b) << endl;
    }
    else if (b == 0) {
        cout << "Second value is zero. Using default value of 4." << endl;
        cout << "Sum: " << sum(a, 4) << endl;
    }
    else {
        cout << "Sum: " << sum(a, b) << endl;
    }

    return 0;
}

