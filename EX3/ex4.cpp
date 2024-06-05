#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void){
    ofstream outFile{"t1.txt", ios::out };
    int account;
    string name;
    double balance;
    while(cin >> account >> name >> balance){
        outFile << account << name << balance << endl;
    }
    cout << "Success!" << endl;
    outFile.close();
}