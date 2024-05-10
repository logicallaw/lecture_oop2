//+= overloading
#include <iostream>
using namespace std;
class Tmp{
private:
    int x, y;
public:
    explicit Tmp(int x)
        : x { x } {}
    Tmp& operator+=(int num){
        x += num;
        return *this;
    }
    int getX() const { return x; }
};
int main(void) {
    Tmp t1{5};
    (t1 += 10) += 15;
    cout << t1.getX() << endl;
}