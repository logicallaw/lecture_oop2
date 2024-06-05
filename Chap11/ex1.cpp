#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void){
    ifstream inFile{ "/Users/jun/Desktop/oop2_clion/Chap11/text.txt", ios::in};
    string line;
    while(getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

}