#include <iostream>
using namespace std;
template<typename T, int arraySize>
class Tmp{
private:
    T* arr;
public:
    Tmp() : arr{ new T[arraySize] } {}
    int getSize() const { return arraySize * sizeof(Tmp); }
};

int main(void)
{
    Tmp<int, 10> t1;
    cout << t1.getSize() << endl;
}