//업캐스팅된 포인터 변수의 오버라이딩 함수 호출
#include <iostream>
using namespace std;
class Tmp{
public:
    virtual void sayHello() const {
        cout << "sayHello in Tmp" << endl;
    }
};
class SubTmp:public Tmp{
public:
    void sayHello() const{
        cout << "sayHello in SubTmp" << endl;
    }
};

int main(void){
    Tmp* t = new Tmp;
    t->sayHello(); //sayHello in Tmp

    SubTmp st;
    t = &st;
    t->sayHello(); //sayHello in SubTmp
    //업캐스팅된 t에서 sayHello() 호출시 오버라이딩된 sayHello()가 호출된다.

    return 0;
}