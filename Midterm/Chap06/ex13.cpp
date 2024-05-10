#include <iostream>
using namespace std;
class TmpBase{
public:
    virtual void start(){ cout << "start" << endl; }
    void end(){ cout << "end" << endl; }
};
class TmpDrA : public TmpBase{
public:
    void start(){ cout << "start Dr A" << endl; }
    void end(){ cout << "end Dr A" << endl; }
};

int main(void){
    TmpBase* t1 = new TmpBase{};
    TmpDrA* t2 = new TmpDrA{};
    t1->start();
    t1->end();
    t1 = t2;
    t1->start();
    t1->end();
    while(true){

    }
}