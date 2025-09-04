#include <iostream>
#include <string>
using namespace std;

class Bank {
    const string accountholder_name;
    const string accountholder_address;
    const string bankbranch_name;
    const string branch_code;
    double initial_balance;  // Corrected variable name

public:
    // Constructor to initialize const members
    Bank(const string& name, const string& address, const string& branch, const string& code, double balance)
        : accountholder_name(name), accountholder_address(address), bankbranch_name(branch), branch_code(code), initial_balance(balance) {}

    void account_holderInfo() const {
        cout << "Branch name: " << bankbranch_name << endl;
        cout << "Name: " << accountholder_name << endl;
        cout << "Address: " << accountholder_address << endl;
        cout << "Your current balance is: " << initial_balance << endl;
    }

    void deposit_money() {
        double amount;
        cout << "Enter the amount: ";
        cin >> amount;
        initial_balance += amount;
        cout << "Your balance is: " << initial_balance << endl;
    }

    void withdraw_money() {
        double amount;
        cout << "Enter the amount: ";
        cin >> amount;
        if (amount <= initial_balance) {
            initial_balance -= amount;
            cout << "Your balance is: " << initial_balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void operation() {
        char x;
        cout << "Do you want to deposit/withdraw? 1 for yes: ";
        cout << endl;
        cin >> x;
        if (x == '1') {
            char y;
            cout << "1 for withdraw and 2 for deposit: ";
            cin >> y;
            if (y == '1') {
                withdraw_money();
            } else if (y == '2') {
                deposit_money();
            } else {
                cout << "Invalid choice!" << endl;
            }
        } else {
            return;
        }
    }
};

int main() {
    Bank o1("naveed ahmad", "uet peshawar hostels", "university branch peshawar", "1486", 10000);
    o1.account_holderInfo();
    o1.operation();  // Perform deposit or withdraw operation for o1
    o1.account_holderInfo();  // Display updated information

    Bank o2("unknown", "uet peshawar hostels", "university branch peshawar", "1486", 10000);
    o2.account_holderInfo();
    o2.operation();  // Perform deposit or withdraw operation for o2
    o2.account_holderInfo();  // Display updated information

    return 0;
}
