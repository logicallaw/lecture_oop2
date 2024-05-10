#include <iostream>
using namespace std;
class Tmp{
public:
    virtual void start() { cout << "start" << endl;}
    virtual void end() { cout << "end" << endl;}
};

class TmpDrA : public Tmp{
public:
    virtual void start() override { cout << "start DrA" << endl; }
    virtual void end() override { cout << "end DrA" << endl; }
};
int main(void){
    Tmp* base = new TmpDrA{};
    base->start(); //start
    base->end(); //end
    delete base;
    return 0;
}