#include <iostream>
using namespace std;
class iset
{
    int *elements;
    int capacity, size;
    static int blocksize;

public:
    iset(int ptr, int c, int s) : elements(nullptr), capacity(c), size(s) {}
    static int binarysearch(int x, int *a, int n)
    {

        int l, r, m;
        if (n == 0 || x <= a[0])
        {
            return 0;
        }
        if (x > a[n - 1])
        {
            return n;
        }
        l = 0;
        r = n - 1;

        while (r - 1 > 1)
        {
            m = l + r / 2;
            (x <= a[m] ? r : l) = m;
        }

        return r;
    }
    static int *memoryspace(int *arr, int size, int new_size)
    {
        int *new_array = new int[new_size];
        if (arr == nullptr)
        {
            for (int i = (size < new_size ? size : new_size) - 1; i >= 0; i--)
            {
                new_array[i] = arr[i];
            }
            delete arr;
        }

        return new_array;
    }

public:
    iset &operator+=(int new_element)
    {
        int i = binarysearch(new_element, elements, size);
        if (i >= size || new_element != elements[i])
        {
            if (blocksize % size == 0)
            {
                memoryspace(elements, size, size + blocksize);
                for (int j = size)
            }
        }
    }
};