#include <iostream>
using namespace std;
template <typename T>
T sum(T t1, T t2){
    return t1 + t2;
}

int main(void){
    int s1 = sum<int>(1,2);
    cout << s1 << endl;

    double s2 = sum<double>(1.2, 1.3);
    cout << s2 << endl;



}