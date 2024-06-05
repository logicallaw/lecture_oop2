#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class ClientData {
public:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;

    ClientData(int accNum = 0, const string& lName = "", const string& fName = "", double bal = 0.0) {
        accountNumber = accNum;
        strncpy(lastName, lName.c_str(), 15);
        lastName[14] = '\0';
        strncpy(firstName, fName.c_str(), 10);
        firstName[9] = '\0';
        balance = bal;
    }
};

void outputLine(ostream& output, const ClientData& record) {
    output << left << setw(10) << record.accountNumber
           << setw(16) << record.lastName
           << setw(11) << record.firstName
           << setw(10) << setprecision(2) << right << fixed << showpoint << record.balance << endl;
}

void createTextFile(fstream& readFromFile) {
    ofstream outPrintFile("print.txt", ios::out);
    if (!outPrintFile) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    outPrintFile << left << setw(10) << "Account" << setw(16) << "Last Name" << setw(11) << "First Name" << right << setw(10) << "Balance" << endl;
    readFromFile.seekg(0);
    ClientData client;
    readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    while (!readFromFile.eof()) {
        if (client.accountNumber != 0) {
            outputLine(outPrintFile, client);
        }
        readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }
}
// Function to display all accounts from the binary file
void displayAllAccounts(fstream& inOutCredit) {

    cout << left << setw(10) << "Account" << setw(16) << "Last Name" << setw(11) << "First Name" << right << setw(10) << "Balance" << endl;
    ClientData client;
    inOutCredit.seekg(0);
    inOutCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    while (!inOutCredit.eof()) {
        if (client.accountNumber != 0) {
            outputLine(cout, client);
        }
        int position = inOutCredit.tellp();
        position += sizeof(ClientData);
        inOutCredit.seekg(position);
        inOutCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }
}
void updateRecord(fstream& updateFile) {
    int accountNumber;
    double transaction;
    cout << "Enter account number (1 to 100, 0 to end input): ";
    cin >> accountNumber;
    while (accountNumber > 0 && accountNumber <= 100) {
        cout << "Enter charge (+) or payment (-): ";
        cin >> transaction;
        updateFile.seekg((accountNumber - 1) * sizeof(ClientData));
        ClientData client;
        updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
        if (client.accountNumber != 0) {
            client.balance += transaction;
            cout << left << setw(10) << accountNumber << setw(16) << client.lastName << setw(11) << client.firstName << setw(10) << setprecision(2) << right << fixed << showpoint << client.balance << endl;
            updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
            updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
        } else {
            cerr << "Account #" << accountNumber << " has no information." << endl;
        }
        cout << "Enter account number: ";
        cin >> accountNumber;
    }
}

void newRecord(fstream& insertInFile) {
    int accountNumber;
    string lastName;
    string firstName;
    double balance;
    cout << "Enter account number (1 to 100, 0 to end input): ";
    cin >> accountNumber;
    while (accountNumber > 0 && accountNumber <= 100) {
        cout << "Enter last name, first name, balance: ";
        cin >> lastName;
        cin >> firstName;
        cin >> balance;
        ClientData client(accountNumber, lastName, firstName, balance);
        insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));
        ClientData temp;
        insertInFile.read(reinterpret_cast<char*>(&temp), sizeof(ClientData));
        if (temp.accountNumber == 0) {
            insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));
            insertInFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
        } else {
            cerr << "Account #" << accountNumber << " already contains information." << endl;
        }
        cout << "Enter account number: ";
        cin >> accountNumber;
    }
}

void deleteRecord(fstream& deleteFromFile) {
    int accountNumber;
    cout << "Enter account number to delete (1 to 100, 0 to end input): ";
    cin >> accountNumber;
    while (accountNumber > 0 && accountNumber <= 100) {
        deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));
        ClientData client;
        deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
        if (client.accountNumber != 0) {
            ClientData blankClient;
            deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));
            deleteFromFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
            cout << "Account #" << accountNumber << " deleted.\n";
        } else {
            cerr << "Account #" << accountNumber << " is empty.\n";
        }
        cout << "Enter account number to delete: ";
        cin >> accountNumber;
    }
}
int main() {
    fstream inOutCredit("credit2.dat", ios::in | ios::app | ios::binary);
    if (!inOutCredit) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter option\n1 - store a formatted text file of accounts\n2 - update an account\n3 - add a new account\n4 - delete an account\n5 - display all accounts\n6 - end program\n? ";
    int choice;
    cin >> choice;

    while (choice != 6) {
        switch (choice) {
            case 1:
                createTextFile(inOutCredit);
                break;
            case 2:
                updateRecord(inOutCredit);
                break;
            case 3:
                newRecord(inOutCredit);
                break;
            case 4:
                deleteRecord(inOutCredit);
                break;
            case 5:
                displayAllAccounts(inOutCredit);
                break;
            default:
                cerr << "Incorrect choice" << endl;
                break;
        }
        inOutCredit.clear(); // Clear EOF flag
        cout << "\n? ";
        cin >> choice;
    }

    return 0;
}