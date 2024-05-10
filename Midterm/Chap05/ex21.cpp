#include <iostream>
using namespace std;
class Tmp{
public:
    explicit Tmp(int a, int b, int c)
        : a{ a },b{ b },c{ c }{}
private:
    int a;
    int b;
    int c;
};

int main(void){
    Tmp t1{1,2,3};
    Tmp t2{1,2};
    Tmp t3{1};
    Tmp t;
}