#include <iostream>
#include <string>
using namespace std;
class BaseTmp{
private:
    string a = 0;
protected:
    string b = 0;
public:
    BaseTmp(string a, string b)
        : a{ a }, b{ b } {}
    string getA() const { return a; }
    string getB() const { return b; }
    virtual string getInfo() const{ return getA() + " " + getB();}
};

class SubTmp : public BaseTmp{
private:
    string subA = 0;
    string subB = 0;
public:
    SubTmp(string a, string b, string subA, string subB)
        : BaseTmp(a, b), subA{ subA }, subB{ subB } {
    }
    string getSubA() const{ return subA; }
    string getSubB() const{ return subB; }
    virtual string getInfo() const override{
        return BaseTmp::getInfo() + " " + getSubA() + " " + getSubB(); }
};

int main(void){
    BaseTmp b1{"1","2"};
    SubTmp s1{"3","4","5","6"};

    cout << s1.getInfo() << endl;
}



