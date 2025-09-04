#include <iostream>
#include <cmath>
using namespace std;
class rectanguler
{
    int redius, angle;

public:
    rectanguler(int r, int i) : redius(r), angle(i) {}
    rectanguler() : redius(0), angle(0) {}
    rectanguler operator+(const rectanguler &other)
    {
        double x1 = redius * cos(angle);
        double y1 = redius * sin(angle);
        double x2 = other.redius * cos(other.angle);
        double y2 = other.redius * sin(other.angle);
        cout << "Rectanguler::" << endl;
        cout << "" << x1 << "+ i" << y1 << endl;
        cout << "" << x2 << "+ i" << y2 << endl;
        cout << "Sum" << endl; 
        cout << ":" << x1 + x2 << "+ i" << y2 + y1 << endl;
        return rectanguler(x1+x2,y1+y2);
    }
    void display()
    {
        cout << "enter values polar Form(orignal)" << endl;
        cout << "radius:" << redius << "<" << angle << endl;
    }
};
int main()
{
    rectanguler o1(3, 45);
    o1.display();
    rectanguler o2(5, 45);
    o2.display();
    rectanguler o3 = o1 + o2;
    return 0;
}