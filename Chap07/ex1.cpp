#include <iostream>
using namespace std;
int main(void){
//    int a = 10;
//    int* pa = &a;
//    cout << pa << endl;
//    cout << &pa << endl;
//    cout << &a << endl;

    const char* p1 = "pby";
    const char* p2 = "pby";
    cout << static_cast<const void*>(p1) << endl;
    cout << static_cast<const void*>(p2) << endl;
    cout << &p1 << endl;
    cout << &p2 << endl;
    return 0;

}