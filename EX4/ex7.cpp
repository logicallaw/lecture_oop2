#include <iostream>
using namespace std;
class A{
private:
    int _a;
public:
    A(){}
    A(int a) : _a{ a } {}
};
class B : public A{
public:
    B(int a) : A(a) {}
    void temp() {}
};
int main(void){
    B b(5);

}