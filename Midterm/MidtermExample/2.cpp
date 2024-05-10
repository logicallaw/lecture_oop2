//destructor에 virtual을 사용하여 자식에서 오버라이딩을 통해
//자식 객체 delete 방법을 구현해야한다.
//자식 객체 타입이 부모타입으로 업캐스팅 되어있고 delete하면
//virtual로 destructor를 구현하지 않으면 자식 destructor는 불리지 않는다.
#include <iostream>
using namespace std;
class Tmp{
private:
    int* ptr = new int[5];
public:
   ~Tmp(){
        delete ptr;
        cout << "ptr is deleted" << endl;
    }
};
class TmpA : public Tmp{
private:
    int* ptrA = new int[5];
public:
    ~TmpA() {
        delete ptrA;
        cout << "ptrA is deleted" << endl;
    }
};
int main(void){
    Tmp* t1 = new TmpA;
    delete t1;
}