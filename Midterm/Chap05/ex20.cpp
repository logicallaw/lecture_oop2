#include <iostream>
using namespace std;
class Tmp{
    friend void printInfo(Tmp& t);
private:
    int a = 10;
};

void printInfo(Tmp& t){
    t.a = 10;
}
