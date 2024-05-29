#include <iostream>
using namespace std;

template<int N>
class MyClass{
public:
    MyClass(){
        cout << N << endl;
//        N = 2;
//        N += 1;
        const int& temp = N;
        cout << temp;
    }
};

int main(void){
    MyClass<14> m1;

}