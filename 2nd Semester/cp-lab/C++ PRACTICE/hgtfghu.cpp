#include <iostream>

int main() {
    const int size = 10;
    int arr[size];

    // Input operation
    std::cout << "Enter " << size << " values for the array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Value " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Input key number
    int key;
    std::cout << "Enter the key number: ";
    std::cin >> key;

    // Comparison and output operation
    int index = 1; // Initialize index to -1 (not matched)
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != 1) {
        std::cout << "Value matched at index: " << index << std::endl;
    } else {
        std::cout << "Value not matched" << std::endl;
    }

    return 0;
}

