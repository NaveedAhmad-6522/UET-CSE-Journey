/*#include <iostream>
using namespace std;
class shape{
    protected:
    double  side_one,side_two;
   public:
   shape():side_one(0.0),side_two(0.0){}
   shape(double x,double y):side_one(x),side_two(y){}
   void get_data(int x,int y){
    side_one=x;
    side_two=y;
   }
   virtual void display()=0;


};
class rectiangle: public shape{ 
    public:
    rectiangle(double xx,double yy):shape(xx,yy){}
    void display()override{
        double area=side_one*side_two;
        cout<<"area of rectingale: "<<area<<endl;
    }




};
class triangal:public shape{
      public:
    triangal(double xx,double yy):shape(xx,yy){}
    void display()override{
        double area=side_one*side_two;
        cout<<"area of tringale: "<<area<<endl;
    }

};
int main(){
    shape* base_class_pointer[2];
    rectiangle obj(3.4,8.3);
    base_class_pointer[0]=&obj;
     triangal obj1(3.4,8.3);
    base_class_pointer[1]=&obj1;
    base_class_pointer[0]->display();
     base_class_pointer[1]->display();
     return 0;



}*/
#include <iostream>
using namespace std;

class shape {
protected:
    double side1, side2;

public:
    shape(double s1 = 0, double s2 = 0) : side1(s1), side2(s2) {}

    void get_data() {
        cout << "Enter side1: ";
        cin >> side1;
        cout << "Enter side2: ";
        cin >> side2;
    }

    virtual void display_area() {
        cout << "Area: " << side1 * side2 << endl;
    }
};

class rectangle : public shape {
public:
    rectangle(double s1 = 0, double s2 = 0) : shape(s1, s2) {}

    void display_area() override {
        cout << "Rectangle Area: " << side1 * side2 << endl;
    }
};

class triangle : public shape {
public:
    triangle(double s1 = 0, double s2 = 0) : shape(s1, s2) {}

    void display_area() override {
        cout << "Triangle Area: " << 0.5 * side1 * side2 << endl;
    }
};

int main() {
    shape* s;

    rectangle rect;
    triangle tri;

    cout << "Enter data for rectangle:" << endl;
    rect.get_data();
    cout << "Enter data for triangle:" << endl;
    tri.get_data();

    s = &rect;
    s->display_area();

    s = &tri;
    s->display_area();

    return 0;
}


