#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
private:
    double radius;
    double angle;

public:
    Polar(double r = 0, double a = 0) : radius(r), angle(a) {}

    Polar operator+(const Polar &p2) const
    {

        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);

        double x2 = p2.radius * cos(p2.angle);
        double y2 = p2.radius * sin(p2.angle);

        double x_sum = x1 + x2;
        double y_sum = y1 + y2;

        double new_radius = sqrt(x_sum * x_sum + y_sum * y_sum);
        double new_angle = atan2(y_sum, x_sum);

        return Polar(new_radius, new_angle);
    }

    void display() const
    {
        cout << "Radius: " << radius << ", Angle: " << angle << endl;
    }
};

int main()
{
    Polar p1(5, 0.5); // Radius = 5, Angle = 0.5
    Polar p2(3, 1.2); // Radius = 3, Angle = 1.2

    Polar sum = p2 + p1; // Adding two Polar objects

    cout << "Polar Point 1: ";
    p1.display();

    cout << "Polar Point 2: ";
    p2.display();

    cout << "Sum of Polar Points: ";
    sum.display();

    return 0;
}
