#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class BankAccount{
public:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
    BankAccount(const int& accNum = 0, const string& lName = "", const string& fName = "", const double& bal = 0)
            : accountNumber{ accNum }, balance { bal } {
        strncpy(lastName, lName.c_str(), 14);
        lastName[14] = '\0';
        strncpy(firstName, fName.c_str(), 9);
        firstName[9] = '\0';
    }
};

int menu();
int menu() {
    int userInput;
    cout << "Enter option" << endl;
    cout << "1 - store a formatted text file of accounts" << endl;
    cout << "2 - update an account" << endl;
    cout << "3 - add a new account" << endl;
    cout << "4 - delete an account" << endl;
    cout << "5 - end program" << endl;
    cout << "? ";
    cin >> userInput;
    return (userInput >= 1 && userInput <= 5) ? userInput : 0;
}

void loadAccount(fstream& bankFile);
void loadAccount(fstream& bankFile){
    int position = 0;
    cout << setw(15) << left << "Account" << setw(15) << left << "LastName" << setw(15) << left << "FirstName" << setw(15) << left << "Balance" << endl;
    while(true) {
        bankFile.seekg(position);
        BankAccount temp;
        bankFile.read(reinterpret_cast<char*>(&temp), sizeof(BankAccount));
        if(temp.accountNumber == 0) break;
        cout << setw(10) << left << temp.accountNumber << setw(15) << left << temp.lastName << setw(15) << left << temp.firstName << setw(10) << left << temp.balance << endl;
        position += sizeof(BankAccount);
    }
}
void createAccount(fstream& bankFile);
void createAccount(fstream& bankFile){
    int userInput;
    cout << "Enter account number (1 to 100, 0 to end input): " << endl;
    while(cin >> userInput && userInput != 0){
        string lName, fName;
        double bal;
        cout << "Enter last name, first name, balance: ";
        cin >> lName >> fName >> bal;
        BankAccount temp{userInput, lName, fName, bal};
        bankFile.seekp((userInput - 1) * sizeof(BankAccount));
        bankFile.write(reinterpret_cast<const char*>(&temp), sizeof(BankAccount));
        cout << "Enter account number (1 to 100, 0 to end input): ";
    }

}
int main(void){
    fstream bankFile{"bank3.dat", ios::in | ios::out | ios::binary };
    BankAccount temp;
    int userInput;
    while((userInput = menu()) != 0){
        switch (userInput) {
            case 1:
                loadAccount(bankFile);
                break;
            case 2:
                break;
            case 3:
                createAccount(bankFile);
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
    cout << "\nSystem is over..." << endl;
    return 0;
}