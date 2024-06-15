#include <iostream>
using namespace std;

template<typename T>
T mul(T t1, T t2){
    return t1 * t2;
}

template<>
int mul(int t1, int t2){
    return t1 * 10;
}

int main(void){
    cout << mul(1,2) << endl;
    cout << mul(1.2,1.2);
}