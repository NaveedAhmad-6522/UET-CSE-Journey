#include <iostream>
using namespace std;

class iset {
private:
    int *a;
    int n;

public:
    iset() {
        a = nullptr;
        n = 0;
    }

    iset(int x) {
        a = nullptr;
        *this += x;
        n = 1;
    }

    ~iset() {
        delete[] a;
    }

    iset& operator+=(int x);
    iset& operator-=(int x);
    int operator()(int x) const;
    void print() const;
    iset& operator=(const iset& S);
    iset(const iset& S);
    operator int() const {
        return n;
    }
};

const int blocksize = 5;

static int* memoryspace(int* p0, int n0, int n1) {
    int* p1 = new int[n1];
    if (p0 != nullptr) {
        for (int i = (n0 < n1 ? n0 : n1) - 1; i >= 0; i--)
            p1[i] = p0[i];
        delete[] p0;
    }
    return p1;
}

int binsearch(int x, int* a, int n) {
    int m, l, r;
    if (n == 0 || x <= a[0]) return 0;
    if (x > a[n - 1]) return n;
    l = 0;
    r = n - 1;
    while (r - l > 1) {
        m = (l + r) / 2;
        (x <= a[m] ? r : l) = m;
    }
    return r;
}

iset& iset::operator+=(int x) {
    int i = binsearch(x, a, n), j;
    if (i >= n || x != a[i]) {
        if (n % blocksize == 0)
            a = memoryspace(a, n, n + blocksize);
        for (j = n; j > i; j--)
            a[j] = a[j - 1];
        n++;
        a[i] = x;
    }
    return *this;
}

iset& iset::operator-=(int x) {
    int i = binsearch(x, a, n), j;
    if (i < n && x == a[i]) {
        n--;
        for (j = i; j < n; j++)
            a[j] = a[j + 1];
        if (n % blocksize == 0)
            a = memoryspace(a, n + 1, n);
    }
    return *this;
}

void iset::print() const {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int iset::operator()(int x) const {
    int i = binsearch(x, a, n);
    return i < n && x == a[i];
}

static int* newcopy(int n, int* a) {
    int* p = new int[n];
    for (int i = 0; i < n; i++)
        p[i] = a[i];
    return p;
}

iset& iset::operator=(const iset& S) {
    if (this != &S) {
        delete[] a;
        n = S.n;
        a = newcopy(n, S.a);
    }
    return *this;
}

iset::iset(const iset& S) {
    n = S.n;
    a = newcopy(n, S.a);
}