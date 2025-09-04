
 #include <iostream>
#include <cstring>

class ShallowCopyTask {
private:
    char* data;

public:
    // Constructor
    ShallowCopyTask(const char* initialData) {
        data = new char[strlen(initialData) + 1];
        strcpy(data, initialData);
    }

    // Shallow Copy Constructor
    ShallowCopyTask(const ShallowCopyTask& other) : data(other.data) {}

    // Method to modify the dynamic array
    void modifyData(const char* newData) {
        delete[] data; // Release existing memory
        data = new char[strlen(newData) + 1];
        strcpy(data, newData);
    }

    // Method to display data
    void displayData() const {
        std::cout << "Data: " << data << std::endl;
    }

    // Destructor
    ~ShallowCopyTask() {
        delete[] data;
    }
};

int main() {
    // Create an object with initial data
    ShallowCopyTask obj1("Initial Data");

    // Create a shallow copy using the copy constructor
    ShallowCopyTask obj2 = obj1;

    // Display data of both objects
    std::cout << "Object 1: ";
    obj1.displayData();

    std::cout << "Object 2: ";
    obj2.displayData();

    // Modify data in obj1
    obj1.modifyData("Modified Data");

    // Display data again
    std::cout << "\nAfter Modification:\n";
    std::cout << "Object 1: ";
    obj1.displayData();

    std::cout << "Object 2: ";
    obj2.displayData(); // Notice that obj2's data is also modified due to shallow copy

    return 0;
}


};