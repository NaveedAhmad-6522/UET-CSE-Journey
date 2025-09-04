#include <iostream>

class Set {
private:
    int *elements;
    int size;
    int capacity;

    static const int blocksize = 5;

    static int* memoryspace(int* p0, int n0, int n1) {
        int* p1 = new int[n1];
        if (p0 != nullptr) {
            for (int i = (n0 < n1 ? n0 : n1) - 1; i >= 0; --i) {
                
                p1[i] = p0[i];
            }
            delete[] p0;
        }
        return p1;
    }

    static int binsearch(int x, int* a, int n) {
        int m, l, r;
        if (n == 0 || x <= a[0]) return 0;
        if (x > a[n - 1]) return n;
        l = 0; r = n - 1;
        while (r - l > 1) {
            m = (l + r) / 2;
            (x <= a[m] ? r : l) = m;
        }
        return r;
    }

public:
    Set() : elements(nullptr), size(0), capacity(0) {}

    Set& operator+=(int x) {
        int i = binsearch(x, elements, size);
        if (i >= size || x != elements[i]) {
            if (size % blocksize == 0) {
                elements = memoryspace(elements, size, size + blocksize);
            }
            for (int j = size; j > i; --j) {
                elements[j] = elements[j - 1];
            }
            ++size;
            elements[i] = x;
        }
        return *this;
    }

    Set& operator-=(int x) {
        int i = binsearch(x, elements, size);
        if (i < size && x == elements[i]) {
            --size;
            for (int j = i; j < size; ++j) {
                elements[j] = elements[j + 1];
            }
            if (size % blocksize == 0) {
                elements = memoryspace(elements, size + 1, size);
            }
        }
        return *this;
    }

    void print() const {
        std::cout << "Set elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Set() {
        delete[] elements;
    }
};

int main() {
    Set mySet;
mySet += 1340;
mySet += 1340;
    mySet += 5;
    mySet += 10;
    mySet += 5; // This will be added since duplicates are allowed
mySet +=35;
mySet += 3;
    mySet.print(); // Output should be: Set elements: 5 10 5

    mySet -= 10; // Remove element 10
    mySet.print(); // Output should be: Set elements: 5 5

    return 0;
}
