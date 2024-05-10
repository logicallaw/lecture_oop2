#include <iostream>
#include <cstring>
using namespace std;
class Tmp{
private:
    char* ptr;
public:
    Tmp(const char* name)
        : ptr {new char[strlen(name) + 1] } {
        for (int i = 0; i < strlen(name); i++){
            ptr[i] = name[i];
        }
        ptr[strlen(name)] = '\0';
    }
    Tmp(const Tmp& origin)
        : Tmp(origin.ptr) {}
    void getInfor() const { cout << ptr << endl; }
};
int main(void){
    Tmp* t1 = new Tmp{"junho"};
    Tmp t2{*t1};
    t2.getInfor();
}