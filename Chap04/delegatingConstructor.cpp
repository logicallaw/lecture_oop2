#include <iostream>
#include <cstring>
using namespace std;
class Tmp{
public:
    Tmp(const char* name)
        : name{ new char[strlen(name) + 1] } {
        for (int i{ 0 }; i < strlen(name); i++){
            (this->name)[i] = name[i];
        }
        (this->name)[strlen(name)] = '\0';
    }
    Tmp(const Tmp& origin)
        : Tmp{ origin.name }{}
    ~Tmp(){ delete name; }
    void display() const{ cout << name << endl; }
private:
    char* name;
};

int main(void){
    Tmp* t1 = new Tmp{"pby"}; //Heap 공간에 Tmp 객체를 생성하여 연결한다.
    Tmp t2{ *t1 }; //포인터의 역참조로 Heap에 있는 객체를 복사생성자로 복사한다.
    //이때, implicit 복사 생성자는 단지 메모리 주소만 복사하기 때문에, 복사가 잘 안된다.
    //그러므로, 위임생성자롤 호출하여 배열을 복사한다.
    delete t1; //Heap 공간 Tmp 객체 소멸.
    t2.display();
    return 0;

}