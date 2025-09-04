#include <iostream>
#include <cstring>
using namespace std;

class ArrayManipulator {
private:
    int* array;
    int size;

public:
    // Constructor
    ArrayManipulator(int s) : size(s) {
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = i + 1;
        }
    }

    // Shallow Copy Constructor
    //ArrayManipulator(const ArrayManipulator& obj1) : array(obj1.array), size(obj1.size) {}

    // Deep Copy Constructor
    ArrayManipulator(const ArrayManipulator& obj) : size(obj.size) {
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = obj.array[i];
        }
    }

    // Method to modify the array
    void modifyArray(int newValue) {
        array[0] = newValue;
    }

    // Method to display the array
    void show() const {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " element of array " << array[i] << endl;
        }
    }

    // Destructor
    ~ArrayManipulator() {
        delete[] array;
    }
};

int main() {
    ArrayManipulator obj(4);
    ArrayManipulator obj1(obj);

    cout << "Object 1:\n";
    obj.show();

    cout << "Object 2:\n";
    obj1.show();

    cout << "\nAfter Modification:\n";
    obj.modifyArray(34);

    cout << "Object 1:\n";
    obj.show();

    cout << "Object 2:\n";
    obj1.show();

    return 0;
}
