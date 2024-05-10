//두 자식간에 관계가 없더라도 static_cast되면 그 클래스의 멤버 호출 가능
#include <iostream>
using namespace std;
class TmpBase{
public:
    virtual void fun() = 0;
};
class TmpDrA : public TmpBase{
public:
    void fun() { cout << "DrA" << endl;}
    void funA() { cout << "funA" << endl; }
};
class TmpDrB : public TmpBase{
public:
    void fun() { cout << "DrB" << endl; }
    void funB() { cout << "funB" << endl; }
};
int main(void){
    TmpBase* base = new TmpDrA;
    base->fun();
    static_cast<TmpDrB*>(base)->fun();
    static_cast<TmpDrB*>(base)->funB();
}