#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

enum class Choice {PRINT = 1, UPDATE, NEW, DELETE, END};

class ClientData{
public:
    ClientData(int = 0, const string& = "", const string& = "", double = 0.0);

    void setAccountNumber(int accountNumberValue){
        accountNumber = accountNumberValue;
    }
    int getAccountNumber() const{ return accountNumber; }

    void setLastName(const string& lastNameString){
        size_t length{lastNameString.size()};
        length = (length < 15 ? length: 14);
        lastNameString.copy(lastName, length);
        lastName[length] = '\0';
    }
    string getLastName() const{ return lastName; }

    void setFirstName(const string& firstNameString){
        size_t length{firstNameString.size()};
        length = (length < 10 ? length: 9);
        firstNameString.copy(firstName, length);
        firstName[length] = '\0';
    }
    string getFirstName() const {return firstName; }

    void setBalance(double balanceValue) { balance = balanceValue; }
    double getBalance() const { return balance; }
private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
};

ClientData::ClientData(int accountNumberValue, const std::string & lastName, const std::string & firstName, double balanceValue)
    : accountNumber{accountNumberValue}, balance{balanceValue} {
    setLastName(lastName);
    setFirstName(firstName);
}



Choice enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData&);
int getAccount(const char* const);

int main(void){
    fstream inOutCredit{"credit.dat", ios::in | ios::out | ios::binary};

    if(!inOutCredit){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    Choice choice;

    while((choice = enterChoice()) != Choice::END){
        switch(choice){
            case Choice::PRINT:
                createTextFile(inOutCredit);
                break;
            case Choice::UPDATE:
                updateRecord(inOutCredit);
                break;
            case Choice::NEW:
                newRecord(inOutCredit);
                break;
            case Choice::DELETE:
                deleteRecord(inOutCredit);
                break;
            default:
                cerr << "Incorrect choice" << endl;
                break;
        }
        inOutCredit.clear();
    }
    return 0;
}
Choice enterChoice(){
    cout << "\nEnter your choice\n"
        << "1 - store a formatted text file of accounts\n"
        << "    called \"print.txt\" for printing\n"
        << "2 - update an account\n"
        << "3 - add a new account\n"
        << "4 - delete an account\n"
        << "5 - end program\n? ";
    int menuChoice;
    cin >> menuChoice;
    return static_cast<Choice>(menuChoice);
}

void createTextFile(fstream& readFromFile){
    ofstream outPrintFile("print.txt", ios::out);
    if(!outPrintFile){
        cerr << "File could not be created." << endl;
        exit(EXIT_FAILURE);
    }
    outPrintFile << left << setw(10) << "Account" << setw(16)
        << "Last Name" << setw(11) << "First Name" << right
        << setw(10) << "Balance" << endl;
    readFromFile.seekg(0);
    ClientData client;
    readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    while(!readFromFile.eof()){
        if(client.getAccountNumber() != 0){
            outputLine(outPrintFile, client);
        }
        readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }
}

void updateRecord(fstream& updateFile){
    int accountNumber{getAccount("Enter account to update")};
    updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

    ClientData client;
    updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if(client.getAccountNumber() != 0){
        outputLine(cout, client);

        cout << "\nEnter charge (+) or payment (-): ";
        double transaction;
        cin >> transaction;

        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + transaction);
        outputLine(cout, client);

        updateFile.seekp((accountNumber - 1) * sizeof(ClientData));

        updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
    }
    else {
        cerr << "Account #" << accountNumber
            << " has no information." << endl;
    }
}

void newRecord(fstream& insertInFile){
    int accountNumber{getAccount("Enter new account number")};

    insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

    ClientData client;
    insertInFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if(client.getAccountNumber() == 0){
        string lastName;
        string firstName;
        double balance;

        cout << "Enter lastname, firstname, balance\n";
        cin >> setw(15) >> lastName;
        cin >> setw(10) >> firstName;
        cin >> balance;

        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);
        client.setAccountNumber(accountNumber);

        insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));

        insertInFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
    }
    else {
        cerr << "Account #" << accountNumber
          << " already contains information." << endl;
    }
}

void deleteRecord(fstream& deleteFromFile){
    int accountNumber{getAccount("Enter account to delete")};

    deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

    ClientData client;
    deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if(client.getAccountNumber() != 0){
        ClientData blankClient;

        deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));

        deleteFromFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));

        cout << "Account #" << accountNumber << " deleted.\n";
    }
    else {
        cerr << "Account #" << accountNumber << " is empty.\n";
    }
}

void outputLine(ostream& output, ClientData& record){
    output << left << setw(10) << record.getAccountNumber()
        << setw(16) << record.getLastName()
        << setw(11) << record.getFirstName()
        << setw(10) << setprecision(2) << right << fixed
        << showpoint << record.getBalance() << endl;
}

int getAccount(const char* const prompt){
    int accountNumber;
    do{
        cout << prompt << " (1 - 100): ";
        cin >> accountNumber;
    } while(accountNumber < 1 || accountNumber > 100);
    return accountNumber;
}