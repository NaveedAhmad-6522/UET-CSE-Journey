#include <iostream>
using namespace std;

class Set {
private:
    int *elements;
    int size;
    int capacity;

public:
    Set() : elements(nullptr), size(0), capacity(0) {}

    // Overloading += operator to add an element to the set
    Set& operator+=(int new_element) {
        // Check if the element already exists in the set
        for (int i = 0; i < size; ++i) {
            if (elements[i] == new_element) {
                return *this;
            }
        }

        // If the set is full, allocate more space
        if (size == capacity) {
            int new_capacity = capacity == 0 ? 1 : capacity * 2;
            int *new_elements = new int[new_capacity];

            // Copy existing elements to the new array
            for (int i = 0; i < size; ++i) {
                new_elements[i] = elements[i];
            }

            // Delete the old array and update the pointers
            delete[] elements;
            elements = new_elements;
            capacity = new_capacity;
        }

        // Add the new element to the set
        elements[size++] = new_element;

        return *this;
    }

    // Overloading -= operator to remove an element from the set
    Set& operator-=(int element_to_remove) {
        int index = -1;

        // Find the index of the element to remove
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element_to_remove) {
                index = i;
                break;
            }
        }

        // If the element is found, remove it
        if (index != -1) {
            for (int i = index; i < size - 1; ++i) {
                elements[i] = elements[i + 1];
            }
            --size;
        }

        return *this;
    }

    // Function to print the elements of the set
    void print() const {
        cout << "Set elements: {";
        for (int i = 0; i < size; ++i) {
            cout << elements[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "}\n";
    }

    // Destructor to free allocated memory
    ~Set() {
        delete[] elements;
    }
};

int main() {
    Set mySet;
    mySet += 4;
    mySet += 43;
    mySet += 4;  // Duplicate element, should not be added
    mySet += 23;
    mySet += 41;

    mySet.print();  // Output should be: Set elements: {4, 43, 23, 41}

    mySet -= 43;
    mySet -= 10;  // Element not in the set, should not change the set

    mySet.print();  // Output should be: Set elements: {4, 23, 41}

    return 0;
}
