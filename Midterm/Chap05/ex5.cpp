#include <iostream>
using namespace std;
class A{ //abstract
public:
    virtual void fun()=0; //pure1
};
class B:public A{ //abstract
public:
    void fun1(){} //pure1 오버라이딩
    virtual void fun2()=0; //pure2
};
class C:public B{
public:
    void fun() { cout << "ss"; }
};
class D:public C{
public:

};
int main(void){
    A a; //abstract
    B b; //abstract
    C c; //abstract(pure virtual function 한개 아직 안해서 오류)
    D d;
}
