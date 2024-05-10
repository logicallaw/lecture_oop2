#include <iostream>
using namespace std;
class Tmp{
public:
    virtual void ft1() const;
    virtual void ft2() const=0;
};
class TmpDr:public Tmp{
public:
    virtual void ft2() const override{
        cout << "TmpDr ft2" << endl;
    }
};
int main(void){
    TmpDr tdr;
    tdr.ft2();
    tdr.ft1();

    return 0;
}