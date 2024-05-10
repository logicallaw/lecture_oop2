#include <iostream>
using namespace std;
int main(){
    int ii;
    cout << cin.rdstate() << endl;
    cout << boolalpha <<cin.eof() << endl;
    cout << boolalpha <<cin.fail() << endl;
    cout << boolalpha <<cin.bad() << endl;
    cout << boolalpha <<cin.good() << endl;
    cin >> ii;
    cout << cin.rdstate() << endl;
    cout << boolalpha <<cin.eof() << endl;
    cout << boolalpha <<cin.fail() << endl;
    cout << boolalpha <<cin.bad() << endl;
    cout << boolalpha <<cin.good() << endl;
}