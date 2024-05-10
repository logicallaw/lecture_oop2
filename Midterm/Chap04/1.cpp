#include <iostream>
using namespace std;
class Tmp{
private:
    int a = 0;
public:
    Tmp& operator+=(int a){
        this->a += a;
        return *this;
    }
    int getA() const{ return a; }
};
int main(void){
    Tmp t1;
    t1 += 2;
    cout << t1.getA() << endl;
    cout << (t1+=3).getA() << endl;
}