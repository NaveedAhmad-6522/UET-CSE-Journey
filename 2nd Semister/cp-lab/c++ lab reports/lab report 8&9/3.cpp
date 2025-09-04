#include <iostream>

double average(int* arr, int size) {
    double sum = 0.0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum / size;
}

int main() {
    int arr[5] = { 10, 20, 30, 40, 50 };

    double avg = average(arr, 5);

    std::cout << "Average: " << avg << std::endl;

    return 0;
}

