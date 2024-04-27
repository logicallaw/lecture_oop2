#include <iostream>
using namespace std;
class Base{
private:
    int a;
public:
    virtual void base()=0;
};
class DrA:public Base{
public:
    virtual void base(){cout << "say Hello!" << endl; }
};

int main(void){
    Base* b = new DrA;
    b->base();
    return 0;
}