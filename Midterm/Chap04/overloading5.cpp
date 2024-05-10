#include <iostream>
using namespace std;
class Tmp{
    friend ostream& operator<<(ostream& out, const Tmp& right){
        out << right.a << endl;
        return out;
    }
private:
    int a;
public:
    explicit Tmp(int a = 0)
        : a{ a } {}
    Tmp operator+(const Tmp& right) { return Tmp{a + right.a};}
    Tmp operator-(const Tmp& right){ return Tmp{a - right.a};}
    Tmp& operator+=(int num) {
        a += num;
        return *this;
    }
    Tmp& operator++(){
        ++a;
        return *this;
    }
    Tmp operator++(int){
        Tmp temp{ *this };
        ++a;
        return temp;
    }

};

int main(void){
    Tmp t1{10};
    Tmp t2{5};
    cout <<(t1+t2);
    return 0;
}