//= overloading
#include <iostream>
#include <cstring>
using namespace std;
class Tmp{
private:
    char* name;
public:
    Tmp(const char* name)
        : name{ new char[strlen(name) + 1]} {
        for (int i = 0; i < strlen(name); i++){
            (this->name)[i] = name[i];
        }
        (this->name)[strlen(name)] = '\0';
    }
    Tmp& operator=(const Tmp& right){
        if (this != &right){
            delete[] name;
            (this->name) = new char[strlen(right.name) + 1];
            for (int i = 0; i < strlen(right.name); i++){
                (this->name)[i] = right.name[i];
            }
            (this->name)[strlen(right.name)] = '\0';
        }
        cout << "= " << name << endl;
        return *this;
    }
};

int main(void){
    Tmp t1{"dlwlrma"};
    t1 = "junho";

}