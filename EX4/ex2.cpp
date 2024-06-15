#include <iostream>
using namespace std;

template<typename T>
class Array{
public:
    explicit Array(int size) : arraySize{ size } {
        ptr = new T[arraySize];
    }
    int getSize() const {
        return arraySize * sizeof(T);
    }
    ~Array(){
        delete[] ptr;
    }
private:
    T* ptr = nullptr;
    int arraySize = 0;
};

int main(void){
    Array<int> arr{ 5 };
    cout << arr.getSize() << endl;

    Array<double> arr1{ 5 };
    cout << arr1.getSize() << endl;
    return 0;
}