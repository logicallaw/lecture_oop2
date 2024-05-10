//constructor에 virtual은 불가능하다.
#include <iostream>
using namespace std;
class Tmp{
public:
    void fun1();
    virtual Tmp(){}
private:
};