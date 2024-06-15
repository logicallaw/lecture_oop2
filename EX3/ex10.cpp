#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    char userInput[50];
    cin >> userInput;
    cin.ignore();
    for(int i{ 0 }; i < strlen(userInput); i++){
        cout << static_cast<int>(userInput[i]) << " ";
    }
}