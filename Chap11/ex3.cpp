#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ifstream inFile{"/Users/jun/Desktop/oop2_clion/Chap11/text.txt", ios::in };

    int account;
    string name;
    double balance;

    inFile.seekg(12);
    while(inFile >> account >> name >> balance){
        cout << account << " " << name << " " << balance << endl;
        inFile.seekg(0, ios::end);
    }

    cout << "\nSuccess!" << endl;
}
