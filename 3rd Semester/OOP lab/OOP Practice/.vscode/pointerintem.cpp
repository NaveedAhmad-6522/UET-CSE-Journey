#include <iostream>
#include <string>

template <typename T, int Size>
class TemplateArray {
private:
    T elements[Size];

public:
    // Constructor
    TemplateArray() {}

    // Getter and setter
    T& operator[](int index){
        if (index < Size) {
            return elements[index];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    // Display the array
    void display() const {
        std::cout << "Array: ";
        for (size_t i = 0; i < Size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create TemplateArray with int type and size 5
    TemplateArray<int, 5> intArray;

    // Set values in the array
    for (size_t i = 0; i < 5; ++i) {
        intArray[i] = i * 10;
    }

    // Display the array
    intArray.display();

    // Create TemplateArray with double type and size 3
    TemplateArray<double, 3> doubleArray;

    // Set values in the array
    for (size_t i = 0; i < 3; ++i) {
        doubleArray[i] = i * 3.14;
    }

    // Display the array
    doubleArray.display();
     TemplateArray<char, 3> stringarr;
      stringarr[0]='a';
      stringarr[1]='b';
      stringarr[2]='c';
      stringarr.display();

    return 0;
}
