#include <iostream>
using namespace std;
class set
{
    int *element;
    int size;
    int capacity;

public:
    set() : element(nullptr), size(0), capacity(0) {}
    set &operator+=(int element)
    {
        for (int i = 0; i < size; i++)
        {
            if element
                [i] == element;
            return->this;
        }
        if (size == capacity)
        {
            int new_capacity = capacity == 0 ? 1 : capacity * 2;
            int *newElements = new int[new_capacity];

            for (int i = 0; i < size; ++i)
            {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = new_capacity;
        }
    }
    return *This;
    void print() const {
        std::cout << "Set elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    // Destructor to free allocated memory
    ~Set() {
        delete[] elements;
    }
};

int main(){
    set my_set;
    my_set+=5;
    my_set+=32;
    my_set+=43;
    print();
    return 0;

}