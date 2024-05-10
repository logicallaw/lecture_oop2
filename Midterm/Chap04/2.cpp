#include <iostream>
using namespace std;
class Tmp{
private:
    int a;
    void increment(){ ++a; };
public:
    explicit Tmp(int a = 0) //conversion 방지.
        : a{ a } {}
    Tmp& operator+=(int num){
        for (int i = 0; i < num; i++){
            increment();
        }
        return *this;
    }
    void display() const {
        cout << a << endl;
    }
};
int main(void){
    Tmp t{ 4 };

    (t+=3)+=5;
    t.display();
    return 0;
}