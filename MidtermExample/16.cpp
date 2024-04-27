#include <iostream>
using namespace std;
class Tmp{
private:
    int a;
    int b;
public:
    Tmp(int a, int b)
        : a { a }, b { b } {}
    int getA() const { return a; }
    int getB() const { return b; }
};
class TmpDr:public Tmp{
    friend ostream& operator<<(ostream& output, const TmpDr& right){
        output << right.getA() << endl;
        output << right.getB() << endl;
        return output;
    }
private:
    int c;
public:
    TmpDr(int a, int b, int c)
        : Tmp(a, b), c { c }{}
};

int main(void){
    TmpDr* dr = new TmpDr(1,2,3);
    cout << dr->getA();
    delete dr;
}