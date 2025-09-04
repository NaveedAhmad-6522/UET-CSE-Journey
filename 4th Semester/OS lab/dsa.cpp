#include <iostream>
#include <string>
#include <limits> 

using namespace std;

// Contact structure
struct Contact {
    int id;
    string name;
    string phoneNumber;
    string email;
    string address;
    Contact* next;
};

// Contact Management System class
class ContactManagementSystem {
    \\
    
private:
    Contact* head;

    // Helper method to create a new contact
    Contact* createContact(int id, const string& name, const string& phoneNumber, const string& email, const string& address) {
        Contact* newContact = new Contact();
        newContact->id = id;
        newContact->name = name;
        newContact->phoneNumber = phoneNumber;
        newContact->email = email;
        newContact->address = address;
        newContact->next = nullptr;
        return newContact;
    }

public:
    ContactManagementSystem() : head(nullptr) {}

    ~ContactManagementSystem() {
        // Properly delete all contacts to free memory
        while (head != nullptr) {
            Contact* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to add a new contact
    void addContact(int id, const string& name, const string& phoneNumber, const string& email, const string& address) {
        Contact* newContact = createContact(id, name, phoneNumber, email, address);
        newContact->next = head;
        head = newContact;
        cout << "New Contact Added Successfully!" << endl;
    }

    // Method to search for a contact by ID
    void searchContactByID(int id) const {
        Contact* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Contact ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phoneNumber << endl;
                cout << "Email: " << temp->email << endl;
                cout << "Address: " << temp->address << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found!" << endl;
    }

    // Method to update a contact by ID
    void updateContact(int id) {
        Contact* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                int choice;
                string newValue;
                while (true) {
                    cout << "\nWhich field do you want to update?\n";
                    cout << "1. Name\n";
                    cout << "2. Phone Number\n";
                    cout << "3. Email\n";
                    cout << "4. Address\n";
                    cout << "5. Done\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch (choice) {
                        case 1:
                            cout << "Enter New Name: ";
                            getline(cin, newValue);
                            temp->name = newValue;
                            cout << "Name Updated Successfully!" << endl;
                            break;
                        case 2:
                            cout << "Enter New Phone Number: ";
                            getline(cin, newValue);
                            temp->phoneNumber = newValue;
                            cout << "Phone Number Updated Successfully!" << endl;
                            break;
                        case 3:
                            cout << "Enter New Email: ";
                            getline(cin, newValue);
                            temp->email = newValue;
                            cout << "Email Updated Successfully!" << endl;
                            break;
                        case 4:
                            cout << "Enter New Address: ";
                            getline(cin, newValue);
                            temp->address = newValue;
                            cout << "Address Updated Successfully!" << endl;
                            break;
                        case 5:
                            return;
                        default:
                            cout << "Invalid Choice! Try again." << endl;
                    }
                }
            }
            temp = temp->next;
        }
        cout << "Contact not found!" << endl;
    }

    // Method to delete a contact by ID
    void deleteContact(int id) {
        Contact* temp = head;
        Contact* prev = nullptr;

        if (temp != nullptr && temp->id == id) {
            head = temp->next;
            delete temp;
            cout << "Contact Deleted Successfully!" << endl;
            return;
        }

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Contact not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Contact Deleted Successfully!" << endl;
    }

    // Method to display all contacts
    void displayContacts() const {
        Contact* temp = head;
        while (temp != nullptr) {
            cout << "Contact ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Phone Number: " << temp->phoneNumber << endl;
            cout << "Email: " << temp->email << endl;
            cout << "Address: " << temp->address << endl << endl;
            temp = temp->next;
        }
    }
};

// Main function to demonstrate Contact Management System
int main() {
    ContactManagementSystem cms;
    int choice, id;
    string name, phoneNumber, email, address;

    while (true) {
        cout << "\n____Contact Management System____" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact by ID" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Delete Contact by ID" << endl;
        cout << "5. Display All Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Use of numeric_limits
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter Contact ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Contact Name: ";
                getline(cin, name);
                cout << "Enter Contact Phone Number: ";
                getline(cin, phoneNumber);
                cout << "Enter Contact Email: ";
                getline(cin, email);
                cout << "Enter Contact Address: ";
                getline(cin, address);
                cms.addContact(id, name, phoneNumber, email, address);
                break;
            case 2:
                cout << "Enter Contact ID: ";
                cin >> id;
                cms.searchContactByID(id);
                break;
            case 3:
                cout << "Enter Contact ID: ";
                cin >> id;
                cms.updateContact(id);
                break;
            case 4:
                cout << "Enter Contact ID: ";
                cin >> id;
                cms.deleteContact(id);
                break;
            case 5:
                cms.displayContacts();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid Choice! Try again." << endl;
        }
    }

    return 0;
}
