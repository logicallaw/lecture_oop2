#include <iostream>
using namespace std;
int main(void){
    int a{ 0 };
    cin >> a;
    while(!cin.eof()){
        if (cin.fail()){
            cin.clear();
            cin.ignore(255,'\n');
        }
        cout << a << endl;
        cin >> a;
    }
    cout << ": " <<cin.fail() << endl;
}