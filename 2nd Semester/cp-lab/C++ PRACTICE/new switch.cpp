#include <iostream>
using namespace std;

int main() {
    int coffee = 0, tea = 0, coke = 0, orange_juice = 0;
    int choice = 0, count = 0;

    do {
        count=count+1;
        cout << "Please input the favorite beverage of person #" << count << ": " << endl;
        cout << "1. Coffee" << endl;
        cout << "2. Tea" << endl;
        cout << "3. Coke" << endl;
        cout << "4. Orange Juice" << endl;
        cout << "-1. Exit" << endl;

        cin >> choice;

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
            case -1:
                break;
            default:
                cout << "Invalid input! Please enter a number from 1 to 4." << endl;
        }
    } while(choice != -1);

    cout << endl << "Survey results:" << endl;
    cout << "================" << endl;
    cout << "Coffee: " << coffee << endl;
    cout << "Tea: " << tea << endl;
    cout << "Coke: " << coke << endl;
    cout << "Orange Juice: " << orange_juice << endl;

    return 0;
}

