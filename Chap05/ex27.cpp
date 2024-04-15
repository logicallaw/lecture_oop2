#include <iostream>
using namespace std;
class Tmp{
public:
    void fun1(){ cout << "fun1 Tmp" << endl; }
    virtual void fun2(){ cout << "fun2 Tmp" << endl; }
};
class SubTmp:public Tmp{
    void fun1(){ cout << "fun1 SubTmp" << endl; }
    virtual void fun2(){ cout << "fun2 SubTmp" << endl;}
};
int main(void){
    Tmp* ptr = new Tmp();
    SubTmp subt1;
    ptr = &subt1;
    ptr->fun1(); //fun1 Tmp; overloading
    ptr->fun2(); //fun2 SubTmp; overriding
    return 0;

}