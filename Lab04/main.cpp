#include <iostream>
using namespace std;
class Tmp{
private:
    int a = 0;
    int b = 1;
    string name;
    static int c;
    static const int d = 2;
public:
    Tmp(string name){ this->name = name; }
    ~Tmp(){ cout << "destructor: " << name << endl ;}
    int getA() { return a; }
    int getB() { return b; }
};

int Tmp::c{ 2 };
Tmp t0{"t0"};
int main(void){
    static Tmp t1{"t1"};
    Tmp t2{"t2"};
    Tmp t3{"t3"};
    static Tmp t4{"t4"};
//    int && a = 5;
//    int b = 10;
//    int d = 1;
//    const int c = 15;
//    const int* pb = &b;
//    int* const pbb = &b;
//
    const int a = 1;
    const int* pa = &a;

}