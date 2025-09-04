#include <iostream>
using namespace std;

int main() {
  int arr[10];
  int key, index;

  // Input values from user
  cout << "Enter 10 values:" << endl;
  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
  }

  // Input key number from user
  cout << "Enter a key number:" << endl;
  cin >> key;

  // Compare key with values in array
  for (int i = 0; i < 10; i++) {
    if (key == arr[i]) {
      index = i;
      break;
    }
    else {
      index = -1;
    }
  }

  // Display result
  if (index != -1) {
    cout << "Value matched at index " << index << endl;
  }
  else {
    cout << "Value not matched" << endl;
  }

  return 0;
}

