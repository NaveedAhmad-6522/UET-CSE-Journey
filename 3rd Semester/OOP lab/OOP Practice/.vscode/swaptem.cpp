#include <iostream>
using namespace std;
template <typename Atype, int size>
class ge_arr
{
    Atype arr[size];

public:
    ge_arr() {}
    Atype &operator[](int index)
    {
        if (index < size)
            return arr[index];
        else
            throw ::out_of_range("error! index must be less then size");
    }
    void display()
    {
        cout << "Array \n";
        for (int i = 0; i < size; ++i)
        {
            cout << "this is element: " << i + 1 << "of index:" << i << arr[i] << endl;
        }
    }
};
int main()
{
    ge_arr<int, 5> intarray;
    ge_arr<double, 5> doublearray;
    ge_arr<string, 5> stringarray;
    for (int i = 0; i < 5; i++)
    {
        intarray[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        doublearray[i] = i*.5;
    }
    intarray.display();
    doublearray.display();

    return 0;
}