#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ifstream inFile{"/Users/jun/Desktop/oop2_clion/Chap11/text.txt", ios::in};
    string userInput;

    while(getline(inFile, userInput)){
        cout << inFile.tellg() << endl;
        cout << userInput << endl;
    }
}