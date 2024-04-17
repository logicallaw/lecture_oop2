#include <iostream>
using namespace std;
class TmpBase{
private:
    int a;
public:
    TmpBase(int a)
        : a { a } {}
    virtual int printInfo() const { return a; }
};
class TmpDr:protected TmpBase{
private:
    int b;
public:
    TmpDr(int a, int b)
        : TmpBase(a), b { b } {}
    int printInfo() const { return TmpBase::printInfo() + b; }
};
int main(void){
    TmpDr d1{1,2};
    cout << d1.printInfo() << endl;
    return 0;
}