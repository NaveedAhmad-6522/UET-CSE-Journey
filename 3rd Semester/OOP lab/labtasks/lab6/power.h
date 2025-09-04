#include <iostream>
#include "base.h"
#include "exponent.h"
using namespace std;
class power : public base, public exponent
{
    int po;
public:
    power(int p) : po(p) {}
    void n1()
    {
        input_base();
        input_exp();
    }
    void show1()
    {
        show_base();
        show_exp();
        for (int i = 0; i < exp; i++)
        {
            po = po * ba;
        }
        cout << "the result :: " << po << endl;
    }
};