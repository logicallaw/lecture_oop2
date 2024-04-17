#include <iostream>
using namespace std;
class A{
public:
    A(){ cout << "default A constructor" << endl; }
    A(int a) : a { a } { cout << "parameter A constructor" << endl; }
    int get() { return a; }
    void set(int a) { this->a = a; }
private:
    int a;
};
class B:public A{
public:
    void compute() { cout << "compute" << endl; }
private:
    int b;
};

int main(void){
    B b(2);
    return 0;
}