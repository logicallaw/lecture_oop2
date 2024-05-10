#include <iostream>
using namespace std;
class Tmp{
public:
    virtual void print()=0;
};
class SubTmp:public Tmp{
private:
    int a;
public:
    void print(){}
    virtual void print2()=0;
    SubTmp(){}
};

int main(void){
    SubTmp sb1;
}

int main(void){

}