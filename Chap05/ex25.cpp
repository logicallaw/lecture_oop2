#include <iostream>
using namespace std;
class Tmp{
private:
    int a;
public:
    Tmp(int a = 0, int b = 0, int c = 0){
        cout << "explicit Tmp constructor" << endl;
    }
};
int main(void){
    Tmp t1{1};
    Tmp t2{1,2};
    Tmp t3{1,2,3};
    Tmp t4{};
}