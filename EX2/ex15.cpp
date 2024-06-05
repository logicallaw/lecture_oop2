#include <iostream>
using namespace std;
int main(void){
    int a { 0 };
    cin >> a;
    while(!cin.eof()){
        if(cin.fail()){
            cout << boolalpha << cin.fail() << endl;
            cin.clear();
            cin.ignore(255, '\n');
        }
        else{cout << a << endl;}
        cin >> a;
    }
}