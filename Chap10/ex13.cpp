#include <iostream>
using namespace std;
template <typename T>
class MyData{
public:
    explicit MyData(T value) : data { value } {}
    T getData() const { return data; }
private:
    T data;
};

template <>
class MyData<char*>{
public:
    explicit MyData(const char* value) : data { new char[strlen(value) + 1] } {
        strcpy(data,value);
    }
    const char* getData() const { return data; }
    ~MyData(){ delete[] data; }
private:
    char* data;
};

int main(void){
    MyData<int> m1{ 5 };
    MyData<char*> m2 { new char[]{'a', 'b', 'c'}};
    cout << m2.getData();
}