#include <iostream>
using namespace std;
template<typename T>
T find_max(T t1, T t2){
    return (t1 >= t2) ? t1 : t2;
}

int main(void){
    cout << find_max(10, 20) << endl;
    cout << find_max(3.14, 2.71) << endl;
    cout << find_max('a', 'z') << endl;
}