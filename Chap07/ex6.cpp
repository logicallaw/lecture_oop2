#include <iostream>
using namespace std;
int main(void){
    cout << cin.rdstate() << endl;
    cout << cin.eof() << endl;
    cout << cin.fail() << endl;
    cout << cin.bad() << endl;
    cout << typeid(cin.rdstate()).name() << endl;

    return 0;
}