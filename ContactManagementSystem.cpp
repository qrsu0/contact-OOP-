#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
contact management that includes adding contact:
    add number, name, company
*/

class Contact {
private:
    int number;
    string name;
    string type;

public:
    void setNewContact(int contactNumber, string fullName, string contactType) {
        this->number = contactNumber;
        this->name = fullName;
        this->type = contactType;
    }

    void displayContact() const {
        cout << "Contact Name: " << name << ", Number: " << number << ", Type: " << type << endl;
    }

    int getContactNumber() const {
        return number;
    }

    string getName() const {
        return name;
    }

    string getType() const {
        return type;
    }
};

void showContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "\nNo contacts available." << endl;
    }
    else {
        for (const auto& contact : contacts) {
            contact.displayContact();
        }
    }
}

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "Welcome, your current contacts are: " << contacts.size() << endl;
        cout << "Menu\n";
        cout << "1. Add contact" << endl;
        cout << "2. Show contacts" << endl;
        cout << "3. Exit" << endl;
        cout << "--" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int number;
            string type;

            cout << "\nEnter the new contact name: ";
            cin.ignore();
            getline(cin, name);
            cout << "\nEnter the number: ";
            cin >> number;
            cout << "\nType (Business - Family - Friend): ";
            cin >> type;

            Contact newContact;
            newContact.setNewContact(number, name, type);
            contacts.push_back(newContact);

            cout << "\nContact added!" << endl;
            break;
        }
        case 2: {
            showContacts(contacts);
            break;
        }
        case 3: {
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }

    } while (choice != 3);

    return 0;
}
