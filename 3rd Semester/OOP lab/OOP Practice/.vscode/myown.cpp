#include <iostrean>
using namespace std;
class iset
{
    int *elements;
    int capacity, size;
    static int blocksize = 5;
    static int *mamory(int *p1, int n1, int n2)
    {
        int *p2 = new int[n2];
        if (p1 != nullptr)
        {
            for ((int i = n1 < n2 ? n1 : n2) - 1; i >= 0; i--)
            {
                p2[i] = p1[i];
                delete[] p1;
            }
        }
        return p2;
    }

    static int binarysearch(int x, int *a, int n)
    {

        int l, r, m;
        if (n == 0 || x <= a[0])
        {
            return 0;
        }
        if (x >= a[n - 1])
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
    public:
    
};