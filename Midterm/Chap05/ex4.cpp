//virtual 함수는 non-static function만 가능.
#include <iostream>
using namespace std;
class Tmp{
public:
    virtual static void getHI();
};
class Sub1Tmp:public Tmp{
public:

};
void Tmp::getHI() { cout << "HI" << endl;}