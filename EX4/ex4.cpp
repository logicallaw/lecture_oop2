#include <iostream>
using namespace std;
template<typename T>
class Array{
public:
    explicit Array(int size) : arraySize{ size }{
        ptr = new T[arraySize];
    }
    int getSize() const{
        return arraySize * sizeof(T);
    }
private:
    T* ptr = nullptr;
    int arraySize = 0;
};
int main(void){
    Array<int> arr1{ 3 };
    Array<double> arr2{ 5 };
    cout << arr1.getSize() + arr2.getSize() << endl;
    return 0;
}