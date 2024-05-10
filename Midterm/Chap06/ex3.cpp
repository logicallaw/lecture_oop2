//자식클래스에서 부모클래스를 protected로 상속 받았다면
//부모클래스의 멤버가 public일지라도 외부에서 접근이 불가능하다.
//단, 자식 클래스는 접근 권한에 따라 public은 상관없이 외부에서 접근이 가능하다.
#include <iostream>
using namespace std;
class A{
public:
    A(int a)
        : _a{ a }{}
    int getA() const { return _a; }
private:
    int _a;
};
class B:protected A{
public:
    B(int a, int b)
        : A(a), _b{ b } {}
    int getB() const { return _b; }
private:
    int _b;
};
int main(void){
    B b1(1,2);

    cout << b1.getA() << endl;
    cout << b1.getB() << endl;
    return 0;
}