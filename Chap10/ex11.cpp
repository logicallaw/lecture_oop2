#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b){
    return a + b;
}

template <>
const char* add(const char* a, const char* b){
    return "char*";
}

int main(){
    cout << add(1, 2) << endl;
    cout << add("wook", "lee") << endl;
}