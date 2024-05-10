#include <iostream>
using namespace std;
int main(){
    const char* const word{"junho"};

    cout << word << endl; //junho
    cout << static_cast<const void*>(word) << endl;
    cout << &word << endl;
}