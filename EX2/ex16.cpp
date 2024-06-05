#include <iostream>
using namespace std;
int main(void){
    cout << "Type any strings you want to convert." << endl;
    /* Fill in here */
    char c;
    while(cin.get(c)){
        if(c == '\n'){
            cout << endl;
        }
        else {
            cout << static_cast<int>(c) << " ";
        }
    }
    return 0;
}