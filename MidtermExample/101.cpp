#include <iostream>
using namespace std;
class A{
private:
    int _n{1};
public:
    A(){}
    A(A& a){}
};
class B{
private:
    A _a;
    int _n;
public:
    B(int n, A& a)
        : _n{ n }, _a { a } {}
    void print(){
        cout << "n : " << _n << endl;
    }
};
int main(void){
    A a;
    B b(2,a);
    b.print();
}