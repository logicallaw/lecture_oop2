//배열연산자(동시에, const), 증감연산자(동시에, int) 오버로딩시 꼭 주의해야한다.
#include <iostream>
using namespace std;
class Tmp{
private:
    int a;
    int* ptr = new int[5];
public:
    Tmp(){}
    Tmp& operator++(){
        ++a;
        return *this;
    }
    Tmp operator++() const {
        Tmp temp = *this;
        return temp;
    }
    int& operator[](int index){
        return ptr[index];
    }
    int operator[](int index) const {
        return ptr[index];
    }
};

void print(const Tmp& t){
    cout << t[2] << endl;
}
int main(void){
    Tmp t1;
    t1[2] = 3;
    cout << t1[2] << endl;
    print(t1);
}