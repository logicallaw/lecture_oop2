#include <iostream>
using namespace std;
template<typename T>
class Array{
private:
    T* array;
    int size;
public:
    Array(int size)
        : array{ new T[size] }, size{ size } {}
    void printArray() const{
        for(int i = 0; i < size; i++) {
            cout << array[i] << endl;
        }
    }
};