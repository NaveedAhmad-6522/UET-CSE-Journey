#include <iostream>
using namespace std;
class first
{
protected:
    int f;

public:
    void f_input()
    {
        cout << "enter f \n";
        cin >> f;
    }
};
class second : public first
{
protected:
    int s;

public:
    void s_input()
    {
        f_input();
        cout << endl;
        cout << "enter s \n";
        cin >> s;
    }
};

class third : public second
{
protected:
    int t;

public:
    void t_input()
    {
        s_input();
        cout << "enter t\n";
        cin >> t;
    }
    void max()
    {
        if (f > t > s)
        {
            cout << "maximum number is f :" << f << endl;
        }
        else if (t > f > s)
        {
            cout << "maximum number is t :" << t << endl;
        }
        else
        {
            cout << "maximum number is s :" << s << endl;
        }
    }
};
int main()
{
    third o1;
    o1.t_input();
    o1.max();
    return 0;
}