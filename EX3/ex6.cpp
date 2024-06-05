#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ifstream inFile{ "t1.txt", ios::in };

    string userInput;
    inFile.seekg(11);
    while(getline(inFile, userInput)){
        cout << userInput << endl;
        inFile.seekg(0, ios::end);
    }
}