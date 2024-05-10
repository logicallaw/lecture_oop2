#include <iostream>
using namespace std;
class USB{ //abstract
public:
    virtual void readUSB()=0;
    virtual void writeUSB(){
        cout << "Can't write to USB" << endl;
    }
};

class USBA:public USB{ //abstract
public:
    virtual void connectA()=0;
};

class USBC:public USB{
public:
    virtual void connectC()=0;
};

class S22:public USBC{ //abstract
private:
    string name;
public:
    S22(string name)
        : name{ name }{}
    //overriding
    virtual void readUSB() override{
        cout << name << ": USB read" << endl;
    }
    virtual void connectC() override{
        cout << name << ": USB-C connected" << endl;
    }
    virtual void writeUSB() override{
        cout << name << ": USB write" << endl;
    }
};

class MP3:public USBA{ //concrete class
private:
    string name;
public:
    MP3(string name)
        : name{ name } {}
    virtual void readUSB() override{
        cout << name << ": USB read" << endl;
    }
    virtual void connectA() override{
        cout << name << ": USB-A connected" << endl;
    }
};

void connectUSB(USB* u){
    //다운캐스팅 성공여부로 타입검사를 진행한다.
    //dynamic_cast<class-type>(variable)
    //다운캐스팅 실패하면 nullptr 리턴하거나 예외를 발생한다. 이는 false를 의미한다.
    if(dynamic_cast<S22*>(u)){
        dynamic_cast<S22*>(u)->connectC();
    }
    else if (dynamic_cast<MP3*>(u)){
        dynamic_cast<MP3*>(u)->connectA();
    }
}
void readUSB(USB* u){ u->readUSB(); }
void writeUSB(USB* u){ u->writeUSB(); }

int main(void) {
    S22 *s22 = new S22("s22"); //주소
    MP3 *mp3 = new MP3{"mp3"}; //주소
    //USB** hub = new USB*[] {s22, mp3}; //2차원 포인터 배열
    USB *hub[] = {s22, mp3}; //이는 객체생성이 아닌 타입 제공이라서 가능.
    //USB* hub = new USB[]{ s22, mp3}; -> USB의 constructor 를 호출하기 때문에 에러.
    for (USB *u: hub) {
        connectUSB(u);
        readUSB(u);
        writeUSB(u);
    }

    for (int i{ 0 }; i < 2; i++){
        delete hub[i];
    }

    return 0;
}

