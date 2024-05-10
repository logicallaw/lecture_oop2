#include <iostream>
using namespace std;
class A{ //abstract
public:
    A(){ cout << "constructor of A " << endl; }
    virtual void fun(){}
};
class B:public A{ //abstract
public:
    B(){ cout << "constructor of B" << endl;}
    void fun1(){}
    virtual void fun2(){}
};

int main(void){
    A a;
    B b;
    return 0;
}
