#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;

    BankAccount(int accNum = 0, const char* lName = "", const char* fName = "", double bal = 0.0) {
        accountNumber = accNum;
        strncpy(lastName, lName, 15);
        strncpy(firstName, fName, 10);
        balance = bal;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Balance: " << balance << endl;
    }
};

void saveAccount(const BankAccount& account, const string& filename) {
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&account), sizeof(BankAccount));
    outFile.close();
}

void loadAccount(BankAccount& account, const string& filename, int accountNumber) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(BankAccount))) {
        if (account.accountNumber == accountNumber) {
            inFile.close();
            return;
        }
    }
    cerr << "Account not found." << endl;
    inFile.close();
}

int main() {
    //원본 account1객체.
    BankAccount account1(123, "Doe", "John", 1500.50);
    string filename = "accounts.dat";

    //전역함수
    saveAccount(account1, filename);

    //복사할 Account 객체
    BankAccount loadedAccount;
    //전역함수
    loadAccount(loadedAccount, filename, 123);
    loadedAccount.display();

    return 0;
}