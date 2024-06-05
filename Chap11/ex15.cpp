#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class BankAccount{
public:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
    BankAccount(const int& accNum = 0, const char* lName = "", const char* fName = "", const double& bal = 0)
            : accountNumber{ accNum }, balance { bal } {
        strcpy(lastName, lName);
        strcpy(firstName, fName);
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

void printAllAccount(fstream& bankFile);
void printAllAccount(fstream& bankFile){
    BankAccount temp;
    bankFile.seekp(0, ios::beg);
    cout << setw(15) << left << "Account" << setw(15) << left << "LastName" << setw(15) << left << "FirstName" << setw(15) << left << "Balance" << endl;
    while(bankFile.read(reinterpret_cast<char*>(&temp), sizeof(BankAccount))) {
        cout << setw(10) << left << temp.accountNumber << setw(15) << left << temp.lastName << setw(15) << left << temp.firstName << setw(10) << left << temp.balance << endl;
    }
}
void createAccount(fstream& bankFile);
void createAccount(fstream& bankFile){
    int userInput;
    cout << "Enter account number (1 to 100, 0 to end input): " << endl;
    while(cin >> userInput && userInput != 0){
        char lName[15];
        char fName[10];
        double bal;
        cout << "Enter last name, first name, balance: ";
        cin >> lName >> fName >> bal;
        BankAccount temp{userInput, lName, fName, bal};
        bankFile.write(reinterpret_cast<const char*>(&temp), sizeof(BankAccount));
        cout << "Enter account number (1 to 100, 0 to end input): ";
    }

}
int main(void){
    fstream bankFile{"bankEx156.dat", ios::in | ios::app | ios::binary };
    int userInput;
    while((userInput = menu()) != 0){
        switch (userInput) {
            case 1:
                printAllAccount(bankFile);
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
    bankFile.close();
    cout << "\nSystem is over..." << endl;
    return 0;
}