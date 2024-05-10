#include <iostream>
using namespace std;
class Tmp{
private:
    static int a;
public:
    static void printA(){ cout << a << endl; }
};

int Tmp::a{1};
int main(void){
    Tmp::printA();
    return 0;
}
