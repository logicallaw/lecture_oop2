#include <iostream>
using namespace std;
class TmpBase{
public:
    TmpBase() { cout << "default Base constructor" << endl; }
    TmpBase(int a) { cout << "parameter Base constructor" << endl; }
};
class TmpDr : public TmpBase{
public:
    TmpDr() { cout << "default Derived constructor" << endl; }
    TmpDr(int a, int b) { cout << "parameter Derived constructor" << endl; }
};

int main(void) {
    TmpDr tr{1,2};
}