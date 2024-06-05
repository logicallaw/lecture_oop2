#include <iostream>
#include <fstream>
using namespace std;

class ClientData {
public:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;

    ClientData(int accountNumber = 0, const char* lastName = "", const char* firstName = "", double balance = 0.0) {
        this->accountNumber = accountNumber;
        strncpy(this->lastName, lastName, 15);
        strncpy(this->firstName, firstName, 10);
        this->balance = balance;
    }
};

int main() {
    // 파일 쓰기
    ofstream outFile("credit.dat", ios::binary);
    ClientData client1(100, "Doe", "John", 1234.56);
    outFile.write(reinterpret_cast<const char*>(&client1), sizeof(ClientData));
    outFile.close();

    // 파일 읽기
    ifstream inFile("credit.dat", ios::binary);
    ClientData client2;
    inFile.read(reinterpret_cast<char*>(&client2), sizeof(ClientData));
    inFile.close();

    // 읽은 데이터 출력
    cout << "Account Number: " << client2.accountNumber << endl;
    cout << "Last Name: " << client2.lastName << endl;
    cout << "First Name: " << client2.firstName << endl;
    cout << "Balance: " << client2.balance << endl;

    return 0;
}