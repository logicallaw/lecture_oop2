#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ofstream outFile{"txt1.txt", ios::out };
    string str;
    int position{ 0 };
    while(cin >> str){
        outFile.seekp(position);
        outFile << str;
        position += 2;
    }

}