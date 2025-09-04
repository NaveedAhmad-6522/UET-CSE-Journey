#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setDimensions(double len, double wid);
    double calculateArea();
};

void Rectangle::setDimensions(double len, double wid) {
    length = len;
    width = wid;
}

double Rectangle::calculateArea() {
    return length * width;
}

int main() {
    Rectangle myRectangle;

    double length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    myRectangle.setDimensions(length, width);

    double area = myRectangle.calculateArea();

    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}

