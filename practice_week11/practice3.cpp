#include <iostream>
using namespace std;
int main(){
    char c;
    string userInput;
    int count = 0;

    cout << "Type a character to count." << endl;
    cin.get(c);
    cin.ignore();

    cout << "Type any input string." << endl;
    getline(cin, userInput);

    for(int i{ 0 }; i < userInput.length(); i++)
        if(userInput[i] == c)
            count++;

    cout << "Count: " << count;
    return 0;
}