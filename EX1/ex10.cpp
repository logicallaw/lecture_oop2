#include <iostream>
using namespace std;
template<typename T>
T maxValue(T t1, T t2){
    return (t1 > t2) ? t1 : t2;
}

int main(void){
    int result = maxValue<int>(1, 2);
    cout << result << endl;
}