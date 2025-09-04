#include <iostream>
#include <algorithm>

class Set {
private:
    int* elements;
    int size;
    int capacity;

public:
    Set() : elements(nullptr), size(0), capacity(0) {}

    // Overloading += operator to add an element to the set
    Set& operator+=(int element) {
        // Check if the element is already in the set
        if (std::find(elements, elements + size, element) == elements + size) {
            // If the set is full, allocate more space
            if (size == capacity) {
                int newCapacity = capacity == 0 ? 1 : capacity * 2;
                int* newElements = new int[newCapacity];

                // Copy existing elements to the new array
                for (int i = 0; i < size; ++i) {
                    newElements[i] = elements[i];
                }

                // Delete the old array and update the pointers
                delete[] elements;
                elements = newElements;
                capacity = newCapacity;
            }

            // Add the new element to the set
            elements[size++] = element;
        }

        return *this;
    }

    // Function to print the elements of the set
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

int main() {
    Set mySet;

    int userInput;
    char addMore;

    do {
        std::cout << "Enter a number to add to the set: ";
        std::cin >> userInput;

        mySet += userInput;

        std::cout << "Do you want to add more numbers? (y/n): ";
        std::cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    mySet.print();

    return 0;
}
