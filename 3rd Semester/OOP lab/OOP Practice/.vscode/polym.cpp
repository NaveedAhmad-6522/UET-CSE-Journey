#include <iostream>
using namespace std;
class base
{
protected:
    int number;
    int word;

public:
    base(int n = 0, int w = 0) : number(n), word(w) {}
    virtual void display()
    {
        cout << "this is base class\n";
    }
};
class derived : public base
{
protected:
    float time;

public:
    derived(int n = 0, int w = 0, float t = 0) : base(n, w), time(t) {}
    void display()
    {
        cout << "this is derived class \n";
    }
};

int main()
{
    base *base_class_pointer;
    derived derived_class_obj1;
    derived derived_class_obj2;
    derived *derived_class_pointer;
    base_class_pointer = &derived_class_obj1;
    base_class_pointer->display();
    derived_class_pointer = &derived_class_obj2;
    derived_class_pointer->display();
    return 0;
}