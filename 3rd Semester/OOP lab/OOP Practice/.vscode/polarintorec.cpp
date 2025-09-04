#include <iostream>
#include <cmath>
using namespace std;
class polar{
    double angle ,redius;
    public:
    polar(double a ,double r):redius(a),angle(r){}
    polar operator+(polar & obj){
        double x1=redius*cos(angle);
        double y1=redius*sin(angle);
        double x2=obj.redius*cos(obj.angle);
        double y2=obj.redius*sin(obj.angle);
        double x_part=x1+x2;
        double y_part=y1=y2;

        double new_radius=sqrt(x_part*x_part+y_part*y_part);
        double new_angle=atan(y_part/x_part);
        return polar(new_radius,new_angle);
        

    }
    void display(){
        cout<<"redius::"<<redius<<endl;
        cout<<"angle::"<<angle<<endl;
    }

};
int main(){
     polar p1(5, 0.5); // Radius = 5, Angle = 0.5
    polar p2(3, 1.2); // Radius = 3, Angle = 1.2

    polar sum = p2 + p1; // Adding two Polar objects

    cout << "Polar Point 1: ";
    p1.display();

    cout << "Polar Point 2: ";
    p2.display();

    cout << "Sum of Polar Points: ";
    sum.display();
    return 0;

}