#include <iostream>
using namespace std;
class Tmp{
public:
    Tmp(){
        cout << "Constructor" << endl;
    }
    ~Tmp() {
        cout << "Destructor" << endl;
    }
private:

};

void fun3(){
    cout << "f3 enter" << endl;
    Tmp t3;
    throw 1;
    cout << "f3 end" << endl;
}
void fun2(){
    cout << "f2 enter" << endl;
    Tmp t2;
    fun3();
    cout << "f2 end" << endl;
}
void fun1() {
    cout << "f1 enter" << endl;
    Tmp t1;
    fun2();
    cout << "f1 end" << endl;
}
int main(void){
    cout << "main enter" << endl;
    try{
        fun1();
    }
    catch (int){
        cout << "catch main" << endl;
    }
    cout << "main end" << endl;
}