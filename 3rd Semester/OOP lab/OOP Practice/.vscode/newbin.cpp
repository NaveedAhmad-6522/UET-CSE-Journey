#include <iostream>
using namespace std;

class iset
{
private:
    int *elements;
    int size;
    int capacity;
    static int block_size;

public:
    iset() : elements(nullptr), size(0), capacity(0) {}
    
    // Corrected function definition: removed '*' from int p1* = new int[n1];
    static int* memoryspace(int *p0, int n0, int n1)
    {
        int *p1 = new int[n1];
        if (p0 != nullptr)
        {
            for (int i = (n0 < n1 ? n0 : n1) - 1; i >= 0; i--)
            {
                p1[i] = p0[i];
            }
            delete[] p0;
        }

        return p1; // Corrected missing semicolon
    }

    // Corrected logic: replaced ',' with '&&' in the if condition
    static int binser(int x, int *a, int n)
    {
        if (n == 0 || x <= a[0])
            return 0;
        if (x >= a[n - 1])
            return n;

        int l, r, m;
        l = 0;
        r = n - 1;
        while (r - 1 > 1)
        {
            m = (l + r) / 2;
            (x <= a[m] ? r : l) = m;
        }
        return r;
    }

    // Corrected syntax: removed '->' from return statement
    iset &operator+=(int x)
    {
        int i = binser(x, elements, size);
        if (i >= size || x != elements[i])
        {
            if (size % block_size == 0)
            {
                // Corrected memoryspace call: added assignment to elements
                elements = memoryspace(elements, size, size + block_size);
            }
            for (int j = size - 1; j >= i; j--)
            {
                elements[j] = elements[j - 1];
            }
            size++;
            elements[i] = x;
        }
        return *this; // Corrected return statement: replaced ->this with *this
    }

    ~iset()
    {
        delete[] elements;
    }

    // Moved print function inside the class and corrected its definition
    void print() const
    {
        cout << "Set elements: ";
        for (int i = 0; i < size; ++i)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

// Initialized static member block_size
int iset::block_size = 5;

int main()
{
    iset mySet;
    mySet += 1340;
    mySet += 1340;
    mySet += 5;
    mySet += 10;
    mySet += 5; // This will be added since duplicates are allowed
    mySet += 35;
    mySet += 3;
    mySet.print(); // Output should be: Set elements: 3 5 10 35

    return 0;
}
