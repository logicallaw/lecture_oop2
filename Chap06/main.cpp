#include <iostream>
using namespace std;
class TmpBase{
public:
    int a = 5;
    int b = 10;
    int c = 15;
};
class TmpDrA: private TmpBase{
public:
    TmpDrA(){}
    void setB() { a = 12; }
    int getB() const { return a; }
};
int main() {
    TmpDrA dra;
    cout << dra.getB();
}
