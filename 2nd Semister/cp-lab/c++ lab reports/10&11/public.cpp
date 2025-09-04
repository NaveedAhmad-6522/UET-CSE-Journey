#include <iostream>
using namespace std;

int main() {
    int x = 4, y = 5;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == 0 || j == 0 || j == y - 1 || i == x - 1) {
                cout << " * ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }

    return 0;
}

