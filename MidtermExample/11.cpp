#include <iostream>
using namespace std;
class Tmp{
private:
    string name;
public:
    Tmp(string name)
        : name{ name } {
        cout << name << ": constructor" << endl;
    }
    ~Tmp() {
        cout << name << ": destructor" << endl;
    }
};
Tmp t0("t0");
static Tmp t1("t1");
int main(void){
    Tmp t2("t2");
    static Tmp t3("t3");
    {
        static Tmp t4("t4");
        Tmp t5("t5");
    }
    Tmp t6("t6");
    static Tmp t7("t7");
}
Tmp t8("t8");
static Tmp t9("t9");



