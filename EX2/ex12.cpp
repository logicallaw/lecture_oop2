#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    const char* word = "dlwlrma";
    const void* v1 = word;
    const char* w1 = static_cast<const char*>(v1);
    cout << w1;

}