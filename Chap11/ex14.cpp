#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    char name[30];
    double balance;

public:
    BankAccount(int accNum = 0, const char* accName = "", double accBalance = 0.0) {
        accountNumber = accNum;
        strcpy(name, accName);
        balance = accBalance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    const char* getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void readFromFile(fstream& file) {
        file.read(reinterpret_cast<char*>(this), sizeof(*this));
    }

    void writeToFile(fstream& file) const {
        file.write(reinterpret_cast<const char*>(this), sizeof(*this));
    }
};

void createAccount() {
    int accountNumber;
    char name[30];
    double balance;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Enter Balance: ";
    cin >> balance;

    BankAccount account(accountNumber, name, balance);

    fstream outFile("accounts.dat", ios::binary | ios::out | ios::app);
    account.writeToFile(outFile);
    outFile.close();

    cout << "Account created successfully!" << endl;
}

void displayAccounts() {
    fstream inFile("accounts.dat", ios::binary | ios::in);
    if (!inFile) {
        cout << "Error opening file" << endl;
        return;
    }

    BankAccount account;
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(account))) {
        account.display();
        cout << endl;
    }

    inFile.close();
}

int main() {
    int choice;

    do {
        cout << "1. Create Account" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}