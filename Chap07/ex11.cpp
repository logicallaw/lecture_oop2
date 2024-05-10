#include <iostream>
using namespace std;
int main(void) {
    int number;
    cout << "cin.rdstate(): " << cin.rdstate() << endl;
    cout << "cin.eof(): " << boolalpha << cin.eof() << endl;
    cout << "cin.fail(): " << boolalpha << cin.fail() << endl;
    cout << "cin.bad(): " << boolalpha << cin.bad() << endl;
    cout << "cin.good(): " << boolalpha << cin.good() << endl << endl;
        cout << "Input a number: ";
        cin >> number;
        cout << "cin.rdstate(): " << cin.rdstate() << endl;
        cout << "cin.eof(): " << boolalpha << cin.eof() << endl;
        cout << "cin.fail(): " << boolalpha << cin.fail() << endl;
        cout << "cin.bad(): " << boolalpha << cin.bad() << endl;
        cout << "cin.good(): " << boolalpha << cin.good() << endl << endl;
        cin.clear();




}