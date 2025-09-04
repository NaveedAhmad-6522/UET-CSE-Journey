#include <iostream>
#include <string>
using namespace std;
template <class T, int size>
class pointer
{
    T is_array[size];

public:
    pointer() {}
    T &operator[](int element)
    {
        if (size > element)
            return is_array[element];
        else
        {
            throw out_of_range("index must be less than size");
        }
    }
    void display() const
    {
        cout << "Printing Array" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << is_array[i] << " ";
        }
    }
};

int main()
{
    pointer<int, 5> intArray;

    for (size_t i = 0; i < 5; ++i)
    {
        (intArray[i]) = i * 1;
    }

    intArray.display();

    pointer<double, 3> doubleArray;

    for (size_t i = 0; i < 3; ++i)
    {
        (doubleArray[i]) = i * 0.2;
    }

    doubleArray.display();

    pointer<string, 7> stringarr;
    stringarr[0] = "n";
    stringarr[1] = "a";
    stringarr[2] = "v";
    stringarr[3] = "e";
    stringarr[4] = "e";
    stringarr[05] = "d";
    stringarr.display();

    return 0;
}