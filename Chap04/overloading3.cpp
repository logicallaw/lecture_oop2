#include <iostream>
using namespace std;
class Tmp{
private:
    int x;
    friend ostream& operator<<(ostream& out, const Tmp& right);

public:
    Tmp(int x)
        : x { x }{}
    //전위증가
    Tmp& operator++(){
        ++x;
        return *this;
    }
    //후의증가
    Tmp operator++(int){
        Tmp t{ *this };
        ++x;
        return t;
    }
};
ostream& operator<<(ostream& out, const Tmp& right){
    out << right.x;
    return out;
}
int main(void){
    Tmp t{ 3 };
    cout << t++ << endl;
    cout << ++t << endl;
}