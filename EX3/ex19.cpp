#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ofstream outFile{"text3.txt", ios::out};
    int account;
    string name;
    double balance;
    int position{ 0 };

    cout << "? ";
    while(cin >> account >> name >> balance){
        outFile.seekp(position);
        cout << "tellp(): " << outFile.tellp() << endl;
        outFile << account << " " << name << " " << balance << endl;
        cout << "\n? ";
        position += 6;
    }
    outFile.close();
    //100 ju200 KI300 jj 303
}