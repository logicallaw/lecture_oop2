#include <iostream>
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    int* pa = &a;
    int* pb = &b;
    *pa += 3;
    *pb += 3;
    cout << "a:" << *pa << ", b:" << *pb << endl;
    int** pp = &pa;


    **pp += 10;
    pp = &pb;
    **pp += 20;
    cout << "a:" << a << ", b:" << b << endl;
    return 0;
}