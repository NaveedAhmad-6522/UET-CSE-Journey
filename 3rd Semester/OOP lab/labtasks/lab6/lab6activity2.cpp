#include <iostream>
using namespace std;

class base
{
protected:
    int ba;

public:
    void input_base()
    {
        cout << "enter ba \n";
        cin >> ba;
    }
    void show_base()
    {
        cout << "ba :: " << ba << endl;
    }
};
class exponent
{
protected:
    int exp;

public:
    void input_exp()
    {
        cout << "enter expa \n";
        cin >> exp;
    }
    void show_exp()
    {
        cout << "exp :: " << exp << endl;
    }
};
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
int main()
{
    power o1(1);
    o1.n1();
    o1.show1();
    return 0;
}