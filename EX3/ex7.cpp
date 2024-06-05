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
    fstream inFile{"tmp3.dat", ios::in | ios::binary };
    while(!inFile.eof()){
        Tmp temp;
        inFile.read(reinterpret_cast<char*>(&temp), sizeof(Tmp));
        cout << temp.getAccountNumber() << " " << temp.getName() << " " << temp.getBalance() << endl;
    }
    inFile.close();
    return 0;
}