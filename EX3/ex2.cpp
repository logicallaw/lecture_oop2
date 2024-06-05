#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    cout << hex << showbase << uppercase;
    cout << 22 << endl;

    cout << 23 << endl;
    cout << 24 << endl;

    cout << setbase(10);

    cout << 22 << endl;
    cout << 23 << endl;
    cout << 24 << endl;
}