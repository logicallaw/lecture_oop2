#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void){
    ofstream outFile{"output.txt", ios::out };
    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    string userInput;
    while(getline(cin, userInput) && userInput.length() != 0){
        outFile << userInput << endl;
    }
    outFile.close();


    ifstream inFile{ "output.txt", ios::in };
    if(!inFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while(inFile >> line){
        cout << line << endl;
    }
    inFile.close();
}