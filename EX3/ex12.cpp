#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    char c;
    cout << "Type a character to count." << endl;
    cin.get(c);
    cin.ignore();

    cout << "Type any input string." << endl;
    char userInput[50];
    cin.getline(userInput, 50, '\n');

    int count = 0;
    for (int i{ 0 }; i < strlen(userInput); i++){
        if (c == userInput[i]){
            count++;
        }
    }
    cout << "Count: " << count << endl;
    return 0;
}