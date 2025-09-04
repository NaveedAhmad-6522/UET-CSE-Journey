#include <iostream>
using namespace std;
class shape
{

protected:
    double Area, Volume;

public:
    virtual double ComputeArea() { return 0; }
    virtual double ComputeVolume() { return 0; }
    virtual void display() = 0;
};
class point : public shape
{
protected:
    double x_axis, y_axis;

public:
    point() : x_axis(0.0), y_axis(0.0) {}
    point(double x, double y) : x_axis(x), y_axis(y) {}
    double ComputeArea()
    {
        return 0;
    }
    double ComputeVolume()
    {
        return 0;
    }
    void display()
    {
        Area = ComputeArea();
        Volume = ComputeVolume();
        cout << "point: "
             << "(X_axis, Y_axis)"
             << " "
             << "(" << x_axis << " , " << y_axis << ")" << endl;
        cout << "(Area,Volume)"
             << "(" << Area << " , " << Volume << ")" << endl;
    }
};
class circle : public point
{
protected:
    double reduis;

public:
    circle() : reduis(0.0) {}
    circle(double x, double y, double r) : point(x, y), reduis(r) {}
    double ComputeArea()
    {
        return 3.1314 * reduis * reduis;
    }
    double ComputeVolume()
    {
        return 0;
    }
    void display()
    {
        Area = ComputeArea();
        Volume = ComputeVolume();
        cout << "circle: "
             << "(redius , X_axis, Y_axis)"
             << " "
             << "(" << reduis << " ," << x_axis << " , " << y_axis << ")" << endl;
        cout << "(Area,Volume)"
             << "(" << Area << " , " << Volume << ")" << endl;
    }
};

int main()
{
    shape *base_class_pointer[2];
    base_class_pointer[0] = new point(3.2, 3.3);
    base_class_pointer[1] = new circle(4.3, 4.4, 2.3);
    for (int i = 0; i < 2; i++)
    {
        base_class_pointer[i]->display();
    }
    for (int i = 0; i < 2; i++)
    {
        delete base_class_pointer[i];
    }

    return 0;
}