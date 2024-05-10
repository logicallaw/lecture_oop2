#include <iostream>
using namespace std;
int main(void){
    int c;
    while(true){
        cout << "Input Number: ";
        cin >> c;
        if (c == 0) break;
        cout << "Number: " << c << endl;
        cout << boolalpha << "cin.eof(): " << cin.eof() << endl;
    }
    cout << "Stop input!" << endl;
    cout << boolalpha << "cin.eof(): " << cin.eof() << endl;
    cout << boolalpha << "cin.eof(): " << cin.eof() << endl;
}