#include <iostream>
using namespace std;
class Tmp{
private:
    int size;
    int* p;
public:
    Tmp(int size)
        : size{ size }, p{ new int[size] }{}
    int& operator[](int index){
        return p[index];
    }
    int operator[](int index) const {
        return p[index];
    }
};

void fun(const Tmp& t){
    cout << t[2] << endl;
}

int main(void){
    Tmp arr{5};
    arr[2] = 3;
    fun(arr);
    return 0;
}