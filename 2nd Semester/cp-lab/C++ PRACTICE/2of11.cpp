#include <iostream>
using namespace std;

struct point {
    int x;
    int y;
};

void drawRectangle(const point& p, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main() {
    point p;
    int width, height;

    cout << "Enter the point coordinates (x, y): ";
    cin >> p.x >> p.y;

    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Enter the height of the rectangle: ";
    cin >> height;

    drawRectangle(p, width, height);

    return 0;
}

