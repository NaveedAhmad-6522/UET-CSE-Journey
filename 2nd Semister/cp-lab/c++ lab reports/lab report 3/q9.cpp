#include <iostream>

using namespace std;

int main() {
  int choice, num_people = 0, coffee = 0, tea = 0, coke = 0, orange_juice = 0;

  while(true) {
    cout << "Please input the favorite beverage of person #" << num_people + 1 << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program\n";
    cin >> choice;

    if(choice == -1) {
      break;
    }

    switch(choice) {
      case 1:
        coffee++;
        break;
      case 2:
        tea++;
        break;
      case 3:
        coke++;
        break;
      case 4:
        orange_juice++;
        break;
      default:
        cout << "Invalid choice. Please try again.\n";
        continue;
    }

    num_people++;
  }

  cout << "The total number of people surveyed is " << num_people << ". The results are as follows:\n";
  cout << "Beverage\tNumber of Votes\n";
  cout << "*****************************************\n";
  cout << "Coffee\t\t" << coffee << endl;
  cout << "Tea\t\t" << tea << endl;
  cout << "Coke\t\t" << coke << endl;
  cout << "Orange Juice\t" << orange_juice << endl;

  return 0;
}

