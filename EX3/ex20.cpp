#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ifstream inFile{"t1.txt", ios::in};
    int account;
    string name;
    double balance;
    while(inFile >> account >> name >> balance){
        cout << "tellg(): " << inFile.tellg() << endl;
        cout << account << " " << name << " " << balance << endl;
        cout << endl;
    }
    inFile.close();
}