#include <iostream>

using namespace std;

class Shape
{
protected:
    double area;
    double volume;

public:
    virtual void computeArea() = 0;   // implement virtual function
    virtual void computeVolume() = 0; // implement virtual function
    virtual void display() const = 0; // Pure virtual function
};

class Point : public Shape
{
protected:
    double x;
    double y;

public:
    Point() : x(0.0), y(0.0) {}

    Point(double x, double y) : x(x), y(y) {}

    void computeArea()
    {
        area = 0.0;
    }

    void computeVolume()
    {
        volume = 0.0; // Volume of a point is zero
    }

    void display() const
    {
        cout << "Point at (" << x << ", " << y << ")\n";
    }
};

class Circle : public Point
{
protected:
    double radius;

public:
    Circle() : Point(), radius(1.0)
    {
        computeArea();
        computeVolume();
    }

    Circle(double x, double y, double radius) : Point(x, y), radius(radius)
    {
        computeArea();
        computeVolume();
    }
    void computeArea() override
    {
        area = 3.141592653589793 * radius * radius;
    }

    void display() const override
    {
        cout << "Circle with center at (" << x << ", " << y << ") and radius " << radius << " whose area is " << area << endl;
    }
};

class Cylinder : public Circle
{
protected:
    double height;

public:
    Cylinder() : Circle(), height(1.0)
    {
        computeArea();
        computeVolume();
    }

    Cylinder(double x, double y, double radius, double height) : Circle(x, y, radius), height(height)
    {
        computeArea();
        computeVolume();
    }

    void computeVolume() override
    {
        volume = 3.141592653589793 * radius * radius * height;
    }

    void display() const override
    {
        cout << "Cylinder with base center at (" << x << ", " << y << "), radius " << radius
             << ", and height " << height << " whose volume is " << volume << endl;
    }
};

int main()
{
    Shape *sh;

    Point point(2.0, 3.0);
    Circle circle(4.0, 5.0, 6.0);
    Cylinder cylinder(1.0, 1.0, 2.0, 3.0);

    sh = &point;
    sh->display();

    sh = &circle;
    sh->computeArea();
    sh->display();

    sh = &cylinder;
    sh->computeVolume();
    sh->display();

    return 0;
}
