#include <iostream>
using namespace std;
template<typename T, int arraySize>
class Array{
private:
    T* array = nullptr;
public:
    Array()
        : array{ new T[arraySize] } {}
    int getSize() const { return arraySize * sizeof(T); }
};

int main(void){
    Array<int, 10> arr1;
    cout << arr1.getSize() << endl; //10 * 4 = 40
}