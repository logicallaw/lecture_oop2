#include <iostream>
using namespace std;
class Tmp{
    friend Tmp operator+(Tmp& left, Tmp& right);
public:
    Tmp(int a, int b)
        : a{ a }, b{ b } {}
    Tmp(int a, int b, int c)
        : Tmp{ a, b } { setC(c); }
    void setC(int c) { this->c = c; }
    void printInfo() const { cout << a << " " << b << " " << c << " "; }
private:
    int a;
    int b;
    int c;
};

Tmp operator+(Tmp& left, Tmp& right){
    return Tmp{left.a + right.a, left.b + right.b, left.c + right.c};
}
int main(void){
    Tmp t1{1,2,3};
    Tmp t2{1,2,3};
    Tmp t3 = (t1 + t2);
    t3.printInfo();

    return 0;

}