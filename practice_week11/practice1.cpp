#include <iostream>
using namespace std;
int main(){
    cout << "Type any strings you want to convert." << endl;
    /* Fill in here. */
    string userInput;
    while(getline(cin, userInput)){
        for(int i = 0; i < userInput.length(); i++)
            cout << static_cast<int>(userInput[i]) << " ";
        cout << "\n";
    }
    return 0;
}