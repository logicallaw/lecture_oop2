#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void){
    ofstream outFile{ "/Users/jun/Desktop/oop2_clion/Chap11/text.txt", ios::app };
    string userInput;
    getline(cin, userInput);
    while(userInput.length() != 0){
        outFile << userInput << endl;
        getline(cin, userInput);
    }
    cout << "\nSuccess!";
    outFile.close();
}
