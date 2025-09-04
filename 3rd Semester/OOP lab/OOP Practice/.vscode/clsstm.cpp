#include <iostream>
#include <string>
using namespace std;
template <class T, class T1>
class templates
{
    T first;
    T1 second;

public:
    templates() {}
    templates(T f, T1 s) : first(f), second(s) {}
    void function()
    {
        cout << " first   second :: " << first << " " << second << endl;
    }
};
int main()
{
    templates<int, double> tem_int_double(3, 6.5);
    templates<string, double> tem_int_double1("navceed", 6.5);
    templates<int, char> tem_int_double2(3, 'h');
    tem_int_double.function();
    tem_int_double1.function();
    tem_int_double2.function();
    return 0;
}