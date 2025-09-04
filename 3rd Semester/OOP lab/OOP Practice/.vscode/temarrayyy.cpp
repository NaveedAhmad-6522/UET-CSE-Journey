#include <iostream>
#include <string>
using namespace std;
template <class type1=int, int size=7>
class arraytem
{
    type1 array[size];

public:
    type1 &operator[](int index)
    {
        if (size > index)
            return array[index];
        else
            throw out_of_range("index must be less then size of array");
    }
    void display()
    {
        cout << "Array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << ",";
        }
    }
};
int main()
{
    arraytem<> array1;

    for (int i = 0; i < 5; i++)
    {
        array1[i] = 3 * i;
    }

    array1.display();
    arraytem<double, 5> array12;
    for (int i = 0; i < 5; i++)
    {
        array12[i] = 3.12 * i;
    }
    cout << endl;
    array12.display();
    arraytem<string, 5> array13;
    array13[0] = "5";
    array13[2] = "5";
    array13[1] = "5";
    array13[4] = "5";
    array13[03] = "5";
    cout << endl;
    array13.display();

    return 0;
}