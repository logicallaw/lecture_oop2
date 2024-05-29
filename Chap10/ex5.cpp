#include <iostream>
using namespace std;
template <typename T, int arraySize>
class Array{
public:
    explicit Array(){
        ptr = new T[arraySize];
    }
    int getSize() const {
        return arraySize;
    }
    ~Array(){
        delete[] ptr;
    }

private:
    T* ptr = nullptr;
};

int main(){
    Array<int, 5> arr;
    cout << arr.getSize() << endl;
}