#include <iostream>
using namespace std;
class Tmp{
private:
    int size;
    int* p;
public:
    Tmp(int size)
        : size{ size }, p{ new int[size]{} } {} //동적으로 배열 생성
    int& operator[](int index){
        return p[index];
    } //Lvalue 리턴:대입연산자로 할당 가능
    int operator[](int index) const {
        return p[index];
    } //Rvalue 리턴:없어도 상관 없음.

};
int main(void){
    Tmp arr{ 5 };
    arr[2] = 3;
    arr[3] = 5;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
}