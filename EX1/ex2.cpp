#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ifstream inFile{"output.txt", ios::in };
    string userInput;
    if(!inFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    while(inFile >> userInput){
        cout << userInput << endl;
    }
    inFile.close();
    return 0;
}