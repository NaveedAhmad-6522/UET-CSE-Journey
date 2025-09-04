#include <iostream>
using namespace std;
class myclass
{
public:
    myclass() { cout << "Normal constructor.\n"; }
    myclass(const myclass &obj) { cout << "Copy constructor.\n"; }
};
myclass f()
{
    myclass ob; // invoke normal constructor
    return ob;  // implicitly invoke copy constructor
}
int main()
{
    myclass a; // invoke normal constructor
    a =f();   // invoke copy constructor
    return 0;
}