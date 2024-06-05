#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ofstream outFile{ "/Users/jun/Desktop/oop2_clion/Chap11/text1.txt", ios::out };
    int account;
    string name;
    double balance;
    int position{ 0 };

    cout << "? ";
    while(cin >> account >> name >> balance){
        outFile.seekp(position);
        cout << "tellp(): " << outFile.tellp() << endl;
        outFile << account << " " << name << " " << balance << endl;
        position += 3;
        cout << "\n";
    }
}