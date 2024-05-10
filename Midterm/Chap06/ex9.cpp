#include <iostream>
using namespace std;
class A{
public:
    void fun(){cout << "A" << endl;}
};
class B:public A{
public:
    void fun(){cout << "B" << endl;}
};
class C:public A{
public:
    void fun(){cout << "C" << endl;}
};
class D:public B, protected C{
};

int main(void){
    D d;
    d.B::fun();
}