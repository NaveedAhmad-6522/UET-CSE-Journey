#include <iostream>
#include <cmath>
using namespace std;

class shape
{
    protected:
    double area,volume;
    public:
    virtual double comput_area()=0;
    virtual double comput_volume()=0;
    virtual void  display()=0;

};
class point :public shape{
    protected:
    double x_axis,y_axis;
    public:
    point():x_axis(0.0),y_axis(0.0){}
    point(double xx,double yy):x_axis(xx),y_axis(yy){}
    double comput_area()override{

return 0;
    }
    double comput_volume()override{

return 0;
    }


void display()override{
    cout<<"arae and volume of point always zero ::(A , V):   (0, 0)"<<endl;
}


};
class circle:public point{
    protected:
    double redius;
    public:
    circle():redius(0.0){}
    circle(double xx,double yy,double zz):point(xx,yy),redius(zz){}
     double comput_area()override{
        double pi=3.13;

return pi*redius*redius ;
    }
    double comput_volume()override{

return 0;
    }


void display()override{
      cout << "Area and volume of cylinder :: (A, V): (" << comput_area() << ", " << comput_volume() << " )" << endl;
}


    

};
class cylinder:public circle{
    protected:
    double height;
    public:
    cylinder():height(0.0){}
    cylinder(double xx,double yy,double zz,double ww):circle(xx,yy,zz),height(ww){}
     double comput_area()override{
    double pi=3.13;

return 2*pi*redius*redius ;
    }
    double comput_volume()override{
    double pi=3.13;

return ((2*pi*redius*redius)+(pi*redius*redius*height)) ;
    }


void display()override{
    cout<<"arae and volume of circle  ::(A , V):"<<"("<<comput_area()<<" ," <<comput_volume()<<"  )"<<endl;
}
    

};
int main(){
    shape* base_class_pointer[3];
    base_class_pointer[0]=new point(3.3,5.7);
    base_class_pointer[1]=new circle(3.3,5.7,2.3);
      base_class_pointer[2]=new cylinder(3.3,5.7,3.4,23.2);
      for(int i=0;i<3;i++){
    base_class_pointer[i]->display();
    cout<<endl;

      }

    return 0;
}
