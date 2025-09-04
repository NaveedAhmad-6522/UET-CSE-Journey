#include<iostream>
using namespace std;

class set {
    int *elements;
    int capacity, size;
    static int blocksize;

public:
    static int* memoryspace(int *p1, int n1, int n2) {
        int *p2 = new int[n2];
        if (p1 != nullptr) {
            for (int i = 0; i < n1; i++) {
                p2[i] = p1[i];
            }
            delete[] p1;
        }
        return p2;
    }

   static int binarysearch(int x, int *a, int n) {
    if (n == 0 || x <= a[0]) return 0;
    if (x >= a[n - 1]) return n;

    int s = 0, e = n - 1, m;

    while (e - s > 1) {
        m = (s + e) / 2;
        if (x <= a[m]) {
            e = m;
        } else {
            s = m;
        }
    }

    return e;
}


    set() : elements(nullptr), capacity(0), size(0) {}
set& operator+=(int x) {
    int i = binarysearch(x, elements, size);
    if (i >= size || x != elements[i]) {
        if ((size + 1) % blocksize == 0) {
            elements = memoryspace(elements, size, size + blocksize);
        }
        for (int j = size; j > i; j--) {
            elements[j] = elements[j - 1];
        }
        elements[i] = x;
        size++;
    }
    return *this;
}


    void print() {
        cout << "{";
        for (int i = 0; i < size; ++i) {
            cout << elements[i];
            if (i < size - 1) cout << " , ";
        }
        cout << "}" << endl;
    }

    ~set() {
        delete[] elements;
    }
};

int set::blocksize = 6;

int main() {
    set myset;
    myset += 5;
    myset += 3;
    myset += 4;
    myset.print();
    return 0;
}
