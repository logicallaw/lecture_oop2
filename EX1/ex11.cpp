#include <iostream>
using namespace std;
template <typename T>
bool compare(T t1, T t2){
    return t1 == t2;
}

template <>
bool compare(char* t1, char* t2){
    return true;
}

int main(void){
    bool result = compare<int>(1, 1);
    bool result2 = compare<char*>(new char[5], new char[10]);
    bool result3 = compare<float>(1.1f, 1.2f);
    cout << boolalpha << result << endl;
    cout << boolalpha << result2 << endl;
    cout << boolalpha << result3 << endl;
}
