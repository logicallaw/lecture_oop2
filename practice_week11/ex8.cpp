#include <iostream>
using namespace std;
int main(void){
    char source[10] = "dlwlrma";
    char dest[10];
    strncpy(dest, source, 10);
    cout << dest << endl;
}