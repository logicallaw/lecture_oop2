//final 함수를 오버라이딩 할 수 없다.
#include <iostream>
using namespace std;
class Tmp{
public:
    virtual void sayHello() const{};
};

class Sub1Tmp:public Tmp{
public:
    virtual void sayHello() const final{ cout << "Sub1" << endl; }
};

class Sub2Tmp::public Sub1Tmp{
public:
    virtual void sayHello() const{ cout << "Sub2" << endl; }
};
