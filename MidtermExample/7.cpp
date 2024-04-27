#include <iostream>
#include <cstring>
using namespace std;
class Tmp{
public:
    char* ptr;
    Tmp(const char* temp) : ptr { new char[strlen(temp) + 1] } {
        for (int i = 0; i < strlen(temp); i++){
            ptr[i] = temp[i];
        }
        ptr[strlen(temp)] = '\0';
        cout << ptr << endl;
    }
};
int main(void){
    Tmp t1{ "junho" };
    cout << (t1.ptr) << endl;
}