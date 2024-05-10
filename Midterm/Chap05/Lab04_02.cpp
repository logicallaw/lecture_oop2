//업캐스팅된 객체를 오버라이딩된 함수 각각 호출한다.
//부모의 타입으로 일관되게 오버라이딩한다.
#include <iostream>
#include <vector>
using namespace std;
class PhoneInterface { //abstract class
private:
    static const int TIMEOUT = 1000;
public:
    virtual void sendCall() const = 0;

    virtual void receiveCall() const = 0;

    virtual void printLogo() const {
        cout << "***Phone***" << endl;
    }
};
class SamsungPhone:public PhoneInterface { //concrete class
public:
    virtual void sendCall() const override {
        cout << "뀨뀨뀨뀨뀨뀨뀨뀨" << endl;
    }

    virtual void receiveCall() const override {
        cout << "Like a Magnetic" << endl;
    }

    virtual void printLogo() const override {
        cout << "***Samsung Phone***" << endl;
    }
};

class Tmp:public PhoneInterface{
public:
    virtual void sendCall() const{
        cout << "Tmp sendCall()" << endl;
    }
};

int main(void){
    //Tmp t;//모두 구현해야지 concrete class가 된다.
    vector<PhoneInterface*> v1;
    SamsungPhone s1;
    SamsungPhone s2;
    v1.push_back(&s1);
    v1.push_back(&s2);
    for (const PhoneInterface* ptrElement : v1){
        ptrElement->sendCall();
        ptrElement->receiveCall();
        ptrElement->printLogo();
        cout << endl;
    }
}