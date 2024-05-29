#include <iostream>
using namespace std;
template <typename T1, typename T2>
double add(T1 num1, T2 num2){
    return num1 + num2;
}

int main(){
    cout << add(1, 2) << endl;
    cout << add(2.1, 3.1) << endl;
    cout << add(2.1, 3) << endl;
}