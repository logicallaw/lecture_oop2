#include <iostream>
using namespace std;
class Tmp{
public:
    Tmp(int a)
            : a { a } {}
    bool operator!=(const Tmp& right) {
        return !(*this == right);
    }
    bool operator==(const Tmp& right){
        return (a == right.a);
    }
private:
    int a;
};

int main(void){
    Tmp t1{2};
    Tmp t2{ 3};

    cout << (t1!=t2) << endl;
}