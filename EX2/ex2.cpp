#include <iostream>
using namespace std;
template<typename T>
class GenericArray{
private:
    T* array;
    int size;
public:
    GenericArray(int size)
        : array{ new T[size] }, size{ size }{}
    ~GenericArray(){ delete[] array; }
    int getSize() const{ return size; }
    T getElement(int index) const{ return array[index]; }
    void setElement(int index, T value) {
        array[index] = value;
    }
};
int main(void){
    GenericArray<int> arr(5);
    arr.setElement(0, 10);
    arr.setElement(1, 20);
    cout << arr.getElement(0) << endl;
    cout << arr.getSize() << endl;
    GenericArray<string> arr3(2);
    arr3.setElement(0, "Hello");
    arr3.setElement(1, "World");
    cout << "Element at index 0: " << arr3.getElement(0) << endl; // 출력: Hello
    cout << "Element at index 1: " << arr3.getElement(1) << endl; // 출력: World
    cout << "Size of array: " << arr3.getSize() << endl; // 출력: 2
}