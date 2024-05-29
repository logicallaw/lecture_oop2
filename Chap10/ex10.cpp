#include <iostream>
using namespace std;
template <typename T>
class MyClass{
private:
    T data;
public:
    MyClass(T value)
        : data{ value } {}
    T getData() const { return data; }
};

int main(void){
    MyClass<char*> s1 ("junho") ;
    cout << s1.getData();
}