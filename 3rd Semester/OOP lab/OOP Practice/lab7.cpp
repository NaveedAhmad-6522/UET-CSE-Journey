#include <iostream>
using namespace std;
class shape // abstrict class
{
public:
    virtual void draw() = 0;
};
class circle : public shape // concret classes
{
public:
    virtual void draw() { cout << "draw a circle " << endl; }
};
class sqaure : public shape
{
public:
    virtual void draw() { cout << "draw a sqaure " << endl; }
};
class rectangle : public shape
{
public:
    virtual void draw() { cout << "draw a rectangle " << endl; }
};
int main()
{
    shape *sh; // this is shape class pointer object
    circle c1;
    sqaure s1;
    rectangle r1;
    sh = &c1;
    sh->draw();
    sh = &s1;
    sh->draw();
    sh = &r1;
    sh->draw();

    return 0;
}