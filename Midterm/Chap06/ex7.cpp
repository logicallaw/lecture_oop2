#include <iostream>
using namespace std;
class TmpBase {
public:
    virtual void fun(){cout << "base class" << endl; };
};
class TmpDrA : public TmpBase{
public:
    virtual void fun(){ cout << "fun() of A" << endl; }
    void funA() { cout << "funA()" << endl; }
};
class TmpDrB : public TmpBase{
public:
    virtual void fun(){ cout << "fun() of B" << endl; }
    void funB() { cout << "funB()" << endl; }
};
int main(void){
    TmpBase* base = new TmpDrB;
    if (TmpDrB* dr = dynamic_cast<TmpDrB*>(base)){
        dr->fun();
        dr->funB();
        dr->TmpBase::fun();
    }
    else
        cout << "fail" << endl;

    return 0;
}