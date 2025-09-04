#include <iostream>

void updateArrayElement(int* index1, int* index2, int* arr) {
    arr[4] = arr[*index1] + arr[*index2];
}

int main() {
    int arr[5];
    int* ptr = arr;

    std::cout << "Enter 4 values for the array: ";
    for (int i = 0; i < 4; i++) {
        std::cin >> *(ptr + i);
    }

    int index1, index2;
    std::cout << "Enter two indexes (0-3): ";
    std::cin >> index1 >> index2;

    updateArrayElement(&index1, &index2, arr);

    std::cout << "Updated fifth index of the array: " << arr[4] << std::endl;

    return 0;
}

