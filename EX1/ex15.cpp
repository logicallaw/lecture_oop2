#include <iostream>
using namespace std;
int main(void){
    const char* ptr1 = new char[]{ "dlwlrma" };
    char* ptr2 = new char[strlen(ptr1)];
    strncpy(ptr2, ptr1, sizeof(ptr2)); //deep copy
    cout << ptr2 << endl;
}