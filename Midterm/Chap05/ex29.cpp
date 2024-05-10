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
int StaticTmp::counter{0};
static StaticTmp s1{"s1"};

int main(void){
    StaticTmp s5{"s5"};
    static StaticTmp s6{"s6"};
    StaticTmp s10{"s10"};
    static StaticTmp s11{"s11"};
    return 0;
}
static StaticTmp s12{"s12"};
StaticTmp s13{"s13"};