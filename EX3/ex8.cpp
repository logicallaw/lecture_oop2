#include <iostream>
#include <fstream>
using namespace std;
class Tmp{
private:
    int accountNumber;
    char name[50];
    double balance;
public:
    Tmp()
            : accountNumber { 0 }, name { "noname" }, balance { 0.0 } {}
    Tmp(int accountNumber, const char* name, double balance)
            :  accountNumber{ accountNumber }, balance{ balance } {
        strncpy(this->name, name, sizeof(strlen(name) + 1));
    }
    Tmp(const Tmp& origin)
            : accountNumber { origin.accountNumber }, balance{ origin.balance } {
        strncpy(this->name, name, sizeof(strlen(origin.name) + 1));
    }
    int getAccountNumber() const { return accountNumber; }
    const char* getName() const{ return name; }
    double getBalance() const { return balance; }
};
int main(void){
    int accountNumber;
    char name[50];
    double balance;

    cout << "Enter accountNumber | Output Stream: ";
    while((cin >> accountNumber) && accountNumber != -1){
        cout << "Enter name, balance: ";
        cin >> name >> balance;

        Tmp t1{accountNumber, name, balance};
        ofstream outFile{"tmp3.dat", ios::app | ios::binary};
        if(outFile){
            outFile.seekp((accountNumber) * sizeof(Tmp));
            outFile.write(reinterpret_cast<const char*>(&t1), sizeof(Tmp));
            outFile.close();
        }
        else{
            cerr << "File could not be opened." << endl;
            exit(EXIT_FAILURE);
        }
        cout << "Enter accountNumber | Output Stream: ";
    }
    cout << "Output Stream is over\n" << endl;
}