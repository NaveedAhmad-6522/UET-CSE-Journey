
#include <iostream>
using namespace std;

class shape{
    protected:
    double Arae ,volume;
    public:
    virtual double  ComputeArea(){

    }
    virtual double ComputeVolume(){

    }
    virtual void display()=0;
};
class point:public shape{
    protected:
    double x_axis,y_axis;
    public:
    point():x_axis(0),y_axis(0){}
    point(double x,double y):x_axis(x),y_axis(y){}
    double ComputeArea()override{
        return 0;

    }
    double ComputeVolume()override{
        return 0;
    }
    void display()override{
        cout<<"point have 0 area as well voulume:"<<endl;

    }

};

class circle :public point{
    protected:
    double redius;
    public:
    circle():redius(0){}
    circle(double x,double y,double r):point(x,y),redius(r){}
    double ComputeArea()override{
        double pi=3.1314;
        return pi*redius*redius;
    }
    double ComputeVolume()override{
        
        return 0;
    }
    void display()override{
        cout<<"circle Arae:  "<<ComputeArea()<<endl;
        cout<<"2D circle volume "<<ComputeVolume()<<endl;
    }

};
class cylender:public circle{
    protected:
    double height;
    public:
    cylender():height(0){}
    cylender(double x,double y,double r,double h):circle(x,y,r),height(h){}
    double ComputeArea()override{
        double pi=3.1314;
        return (2*pi*redius*redius)+pi*redius*redius*height;
    }
     double ComputeVolume()override{
        double pi=3.1314;
        return pi*redius*redius*height;
    }
    void display()override{
        cout<<" Area of cyilender:  "<<ComputeArea()<<endl;
        cout<<"cyilender volume :"<<ComputeVolume()<<endl;
    }


};
int main(){
    
   shape* base_class_pointer[2];
   base_class_pointer[0]=new point(4.4,5.3);
   base_class_pointer[1]=new circle(4.4,5.3,2);
   base_class_pointer[2]=new cylender(4.4,5.3,5.8,3.2);
   for(int i=0;i<3;i++){
    base_class_pointer[i]->display();
    cout<<endl;
   }

    return 0;

}