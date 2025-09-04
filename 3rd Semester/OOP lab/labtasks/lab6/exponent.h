#include <iostream>
using namespace std;

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