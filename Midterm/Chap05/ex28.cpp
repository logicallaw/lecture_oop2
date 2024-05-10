#include <iostream>
#include <vector>
using namespace std;
class Tmp{
public:
    virtual void fun1()=0;
private:
    int a;
};
class SubTmp:public Tmp {
public:
    SubTmp(){}
    void fun1(){ cout << "HI" << endl; }
private:
    int b;
};

int main(void){
    vector<Tmp*> list;
    SubTmp s1;
    SubTmp s2;
    list.push_back(&s1);
    list.push_back(&s2);
    for (Tmp* l : list){
        l->fun1();
    }

}