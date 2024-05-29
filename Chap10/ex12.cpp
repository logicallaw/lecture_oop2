#include <iostream>
using namespace std;
template <typename T>
class MyData{
public:
    explicit MyData(T value) : data{ value } {}
    T getData() const {return data;}
private:
    T data;
};

template <>
