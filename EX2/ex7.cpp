#include <iostream>
using namespace std;
template<typename T>
T add(T t1, T t2){
    cout << "same" << endl;
    return t1 + t2;
}

template<typename T1, typename T2>
double add(T1 t1, T2 t2){
    cout << "Different" << endl;
    return t1 + t2;
}

int main(void){
    cout << add(2.1, 3.2) << endl;
    cout << add(1,2.2) << endl;
}