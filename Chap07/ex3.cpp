#include <iostream>
using namespace std;
int main(){
//    int a{5};
//    int* aPtr;
//    aPtr = &a;
//    cout << a << endl;
//    cout << aPtr << endl;
//    cout << *aPtr << endl;
    const char* word = "dlwlrma";
    cout << word << endl;
    cout << static_cast<const void*>(word) << endl;

    const void* v = word;
    cout << v << endl;
//  const char* c = v;
    const char* c = static_cast<const char*>(v);
    cout << c << endl;
}