#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Forward declaration
class account;

class customer {
public:
    int Customer_ID;
    string Name;
    string Address;
    string Phone_number;
};

class transaction {
public:
    string date;
    string type; // "Deposit" or "Withdrawal"
    double amount;
    account* from_account;
    account* to_account; // Only applicable for transfers
};

class account {
    public:
    string account_number;
    string account_type;
    double balance;
    customer Owner;
    vector<transaction> transactions;

public:
    account(string acc_number, string acc_type, double initial_balance, customer acc_owner)
        : account_number(acc_number), account_type(acc_type), balance(initial_balance), Owner(acc_owner) {}

    void deposit(double amount) {
        balance += amount;
        recordTransaction("Deposit", amount);
        cout << "Amount successfully deposited: " << amount << endl;
        displayBalance();
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            recordTransaction("Withdrawal", amount);
            cout << "Amount successfully withdrawn: " << amount << endl;
            displayBalance();
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void transfer(account& to_account, double amount) {
        if (balance >= amount) {
            balance -= amount;
            to_account.balance += amount;
            recordTransaction("Transfer", amount, &to_account);
            cout << "Amount successfully transferred: " << amount << endl;
            displayBalance();
        } else {
            cout << "Insufficient funds for transfer!" << endl;
        }
    }

    void displayBalance() {
        cout << "Current balance: " << balance << endl;
    }

    void displayTransactionHistory() {
        cout << "Transaction History:" << endl;
        for (const auto& trans : transactions) {
            cout << "Date: " << trans.date << ", Type: " << trans.type << ", Amount: " << trans.amount;
            if (trans.to_account != nullptr) {
                cout << ", To Account: " << trans.to_account->account_number;
            }
            cout << endl;
        }
    }

private:
    void recordTransaction(string trans_type, double trans_amount, account* to_acc = nullptr) {
        transaction trans;
        trans.date = getCurrentDateTime();
        trans.type = trans_type;
        trans.amount = trans_amount;
        trans.from_account = this;
        trans.to_account = to_acc;
        transactions.push_back(trans);
    }

    string getCurrentDateTime() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return buffer;
    }
};

class bank {
    vector<account> accounts;

public:
    void addAccount(account new_account) {
        accounts.push_back(new_account);
    }

    void displayAllAccounts() {
        cout << "All Accounts in the Bank:" << endl;
        for (const auto& acc : accounts) {
            cout << "Account Number: " << acc.account_number << ", Owner: " << acc.Owner.Name << ", Type: " << acc.account_type << endl;
        }
    }
};

int main() {
    // Create customers
    customer customer1{1, "John Doe", "123 Main St", "555-1234"};
    customer customer2{2, "Jane Smith", "456 Oak St", "555-5678"};

    // Create accounts
    account account1("12345", "Savings", 1000.0, customer1);
    account account2("67890", "Checking", 500.0, customer2);

    // Create a bank and add accounts
    bank myBank;
    myBank.addAccount(account1);
    myBank.addAccount(account2);

    // Perform transactions
    account1.deposit(500.0);
    account1.withdraw(200.0);
    account1.transfer(account2, 300.0);

    // Display account information
    myBank.displayAllAccounts();

    // Display transaction history
    account1.displayTransactionHistory();
    account2.displayTransactionHistory();

    return 0;
}
