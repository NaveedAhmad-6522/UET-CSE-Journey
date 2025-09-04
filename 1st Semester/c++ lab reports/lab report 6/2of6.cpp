#include <iostream>
using namespace std;

void minmax(int a, int b, int c, int d) {
    int min_num = a, max_num = a;
    
    if (b < min_num) {
        min_num = b;
    }
    if (c < min_num) {
        min_num = c;
    }
    if (d < min_num) {
        min_num = d;
    }
    
    if (b > max_num) {
        max_num = b;
    }
    if (c > max_num) {
        max_num = c;
    }
    if (d > max_num) {
        max_num = d;
    }
    
    cout << "Minimum number: " << min_num << endl;
    cout << "Maximum number: " << max_num << endl;
}

int main() {
    int a, b, c, d;
    
    cout << "Enter four numbers: " << endl;
    cin >> a >> b >> c >> d;
    
    minmax(a, b, c, d);
    
    return 0;
}

