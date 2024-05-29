#include <iostream>
using namespace std;
template <typename T1, typename T2>
double add(T1 num1, T2 num2){
    return num1 + num2;
}
int main(void){
    cout << add<double, int>(2,1);
}