#include <iostream>
using namespace std;
class shap
{
protected:
   float area, volume;

public:
   virtual float computearea() = 0;
   virtual float computevolume() = 0;
   virtual void display() = 0;
};
class point : public shap
{
protected:
   float xx, yy;

public:
   point() : xx(0), yy(0) {}
   point(float x, float y) : xx(x), yy(y) {}
   float computearea() override
   {
      return 0;
   }
   float computevolume() override
   {
      return 0;
   }
   void display() override
   {
      float area = computearea();
      float volume = computevolume();
      cout << "points :"
           << "( x, y) " << xx << " , " << yy << endl;
      cout << "(area , volume): "
           << "(" << area << " , " << volume << ")" << endl;
   }
};
class circle : public point
{
protected:
   float redius;

public:
   circle() : redius(0) {}
   circle(float x, float y, float r) : point(x, y), redius(r) {}
   float computearea() override
   {
      return 3.1414 * redius * redius;
   }
   float computevolume() override
   {

      return 0;
   }
   void display() override
   {
      float area = computearea();
      float volume = computevolume();
      cout << "circle :"
           << "( x, y) " << xx << " , " << yy << endl;
      cout << "(area , volume): "
           << "(" << area << " , " << volume << ")" << endl;
   }
};
class cylender : public circle
{
protected:
   float height;

public:
   cylender() : height(0.0) {}
   cylender(float x, float y, float r, float h) : circle(x, y, r), height(h) {}
   float computearea() override
   {
      return (3.1414 * redius * redius + 2 * 3.1314 * height * redius);
   }
   float computevolume() override
   {

      return 0;
   }
   void display() override
   {
      float area = computearea();
      float volume = area * height;
      cout << " cylender :"
           << "( x, y) " << xx << " , " << yy << endl;
      cout << "(area , volume): "
           << "(" << area << " , " << volume << ")" << endl;
   }
};

int main()
{
   shap *shape_class_pointers[3];
   shape_class_pointers[0] = new point(3.0, 4.0);
   shape_class_pointers[1] = new circle(3.0, 4.0, 3);
   shape_class_pointers[2] = new cylender(3.0, 4.0, 3, 4.3);
   for (int i = 0; i < 3; i++)
   {
      shape_class_pointers[i]->display();
   }
   for (int i = 0; i < 3; i++)
   {
      delete shape_class_pointers[i];
   }
   return 0;
}