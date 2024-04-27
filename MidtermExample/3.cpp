//다운캐스팅해서 자식 클래스 멤버 호출
#include <iostream>
using namespace std;
class Tmp{
public:
    void display() const{ cout << "base" << endl; }
    virtual ~Tmp() {}
};
class TmpDr : public Tmp{
public:
    void display() const { cout << "Dr" << endl; }
};
int main(void){
    Tmp* base = new TmpDr;
    base->display();
    dynamic_cast<TmpDr*>(base)->display();
}