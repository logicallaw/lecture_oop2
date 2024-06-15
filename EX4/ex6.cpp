#include <iostream>
using namespace std;
class TmpBase{
public:
    TmpBase(){}
    void display() { cout << "Base" << endl; }
};
class TmpDr : public TmpBase{
public:
    TmpDr() {}
    void display() { cout << "Derived" << endl;}
};
int main(void){
    TmpBase* base = new TmpDr;
    base -> display();
    static_cast<TmpDr*>(base)->display();
    return 0;
}