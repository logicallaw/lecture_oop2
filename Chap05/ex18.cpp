#include <iostream>
using namespace std;
class Tmp{
private:
    int* ptr;
    int size;
    int a;
    int b;
public:
    Tmp(int size, int a, int b)
        : ptr{ new int[size] }, a{ a }, b{ b } {}
    int& operator[](int index){ return ptr[index]; }
    int operator[](int index) const { return ptr[index]; }
    bool operator==(const Tmp& right) {
        return (a == right.a) && (b == right.b);
    }
    operator int() { return b; }
    operator double() { return a + 100 + 0.1;}
};

int main(void){
    Tmp t1{ 10, 10, 20 };
    Tmp t2{10, 10, 20};
    bool b1 = true;
    cout << b1 << endl; //1
    cout << (t1 == t2) << endl; //1
    double a = t1;
    cout << a << endl;
}