#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ofstream outFile{"/Users/jun/Desktop/oop2_clion/Chap11/text.txt", ios::app};
    int account;
    string name;
    double balance;

    cout << "? ";
    while(cin >> account >> name >> balance){
        cout << "tellp(): " << outFile.tellp() << endl;
        outFile << account << " " << name << " " << balance << endl;
        cout << "\n? ";
    }


}