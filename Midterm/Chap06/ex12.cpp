#include <iostream>
using namespace std;
class TmpBase{
public:
    virtual void fun() = 0;
};
class TmpDrA:public TmpBase{
public:
    void fun() { cout << "fun() of A" << endl; }
    void funA() { cout << "funA()" << endl; }
    virtual void funAA(){}
};
class TmpDrB:public TmpDrA{
public:
    virtual void fun() { cout << "fun() of B" << endl; }
    void funB() { cout << "funB()" << endl; }
    virtual void funAA(){}
};
int main(void){
    TmpBase* base = new TmpDrA;
    if (TmpDrB* dr = dynamic_cast<TmpDrB*>(base)){
        dr->fun();
        dr->funB();
    }
    else {
        cout << "fail" << endl;
    }
    char a = 'a';
    cout << a;

}