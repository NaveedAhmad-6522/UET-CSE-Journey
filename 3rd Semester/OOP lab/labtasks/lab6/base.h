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