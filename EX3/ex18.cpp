#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(){
    ofstream outFile{"ex18.txt", ios::out };
    char userInput[50];
    cout << "Enter: ";
    cin.getline(userInput, 50);
    outFile << userInput << endl;
    outFile.close();

    ifstream inFile{"ex18.txt", ios::in};
    char line[50];
    while(inFile >> line){
        cout << line << " ";
    }
    inFile.close();
}