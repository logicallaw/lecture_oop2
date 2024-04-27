#include <iostream>
using namespace std;
class StaticTmp{
private:
    static int counter;
    string name;
public:
    StaticTmp(string name)
            : name{ name }{
        cout << ++counter << ": " << name << " Called constructor" << endl;
    }
    ~StaticTmp(){
        cout << --counter << ": " << name << " Called destructor" << endl;
    }
    static int getCounter() { return counter;}
};
int StaticTmp::counter{ 0 };
//global
static StaticTmp s0("s0");
StaticTmp s1("s1");
static StaticTmp s2("s2");
int main(void){
    static StaticTmp s3("s3");
    StaticTmp s4("s4");
    static StaticTmp s5("s5");
    return 0;
}