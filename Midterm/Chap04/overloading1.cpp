// ==/!= operator
#include <iostream>
using namespace std;
class Tmp{
private:
    int x, y;
public:
    explicit Tmp(int x = 0, int y = 0)
        : x{ x }, y { y } {}
    bool operator==(const Tmp& right){
        if (x == right.x && y == right.y)
            return true;
        else
            return false;
    }
    bool operator!=(const Tmp& right){
        return !(*this == right);
    }
};
int main(void){
    Tmp t1{1,2};
    Tmp t2{1,2};
    if(t1 != t2)
        cout << "t1 != t2" << endl;
    else
        cout << "t1 == t2" << endl;
    return 0;
}