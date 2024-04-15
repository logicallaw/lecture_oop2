#include <iostream>
using namespace std;
class Tmp{
private:
    string model;
    string color;
public:
    Tmp();
    virtual ~Tmp();
    virtual void f1()=0;
};

class SubTmp: public Tmp{
private:
    int year;
public:
    SubTmp();
    virtual ~SubTmp();
    virtual void f1() override{}
    virtual void f2()=0;
};

class Sub1Tmp: public SubTmp{
private:
    int age;
public:
    Sub1Tmp();
    virtual void f2(){}
};

int main(void){
    //SubTmp s1; abstract class
    Sub1Tmp s1
}