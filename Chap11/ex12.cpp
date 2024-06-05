#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class ClientData{
    friend void updateRecord(fstream& updateFile);
private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
public:
    ClientData(int accNum = 0, const string& lName = "", const string& fName = "", double bal =  0){
        accountNumber = accNum;
        strncpy(lastName, lName.c_str(), 15);
        lastName[14] = '\0';
        strncpy(firstName, fName.c_str(), 10);
        firstName[9] = '\0';
        balance = bal;
    }
};
void updateRecord(fstream& updateFile){
    int accountNumber;
    double transaction;
    cout <<" Enter account number (1 to 100, 0 to end input): ";
    cin >> accountNumber;
    while(accountNumber > 0  && accountNumber <= 100){
        cout << "Enter charge (+) or payment (-): ";
        cin >> transaction;
        updateFile.seekg((accountNumber - 1) * sizeof(ClientData));
        ClientData client;
        updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
        if(client.accountNumber != 0){
            client.balance += transaction;
            cout << left << setw(10) << accountNumber << setw(16) << client.lastName << setw(11) << client.firstName << setw(10) << setprecision(2) << right << fixed << showpoint << client.balance << endl;
            updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
            updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
        } else {
            cerr << "Account #" << accountNumber << " has no information" << endl;
        }
        cout << "Enter account number: ";
        cin >> accountNumber;
    }
}