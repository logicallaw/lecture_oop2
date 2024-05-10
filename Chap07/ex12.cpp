#include <iostream>
using namespace std;
int main(){
    int value;
    cout << cin.rdstate() << endl;
    cout << cin.eof() << endl;
    cout << cin.fail() << endl;
    cout << cin.bad() << endl;
    cout << cin.good() << endl;
    cin >> value;
    cout << cin.rdstate() << endl;
    cout << cin.eof() << endl;
    cout << cin.fail() << endl;
    cout << cin.bad() << endl;
    cout << cin.good() << endl;
    cin.clear();
    cout << cin.rdstate() << endl;
    cout << cin.eof() << endl;
    cout << cin.fail() << endl;
    cout << cin.bad() << endl;
    cout << cin.good() << endl;
}