#include <iostream>
#include <cstring>
using namespace std;
class Tmp{
private:
    char* name;
public:
    Tmp(const char* name)
        : name{ new char[strlen(name) + 1] } {
        for (int i{ 0 }; i < strlen(name); i++){
            (this->name)[i] = name[i];
        }
        (this->name)[strlen(name)] = '\0';
    }

    Tmp(const Tmp& t) //생성자 위임
        : Tmp{ t.name } {}

    ~Tmp() { delete[] name; }
    void printName() const { cout << name << endl; }
};

int main(void) {
    Tmp* ptr{ new Tmp{ "pby"} };
    Tmp t{ *ptr };
    ptr->printName();

    delete ptr;
    t.printName();
}