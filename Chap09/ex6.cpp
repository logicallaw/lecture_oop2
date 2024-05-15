#include <iostream>
using namespace std;
class myClass{
public:
    myClass(const string& m) : data{ m }{
        cout << "constructor: " << data << endl;
    }
    myClass(const myClass& r) : data{ r.data + " (copy)" }{
        cout << "Copy constructor: " << data << endl;
    }
    string print() const {return data;}
    ~myClass() { cout << "destructor: " << data << endl; }
private:
    string data;
};
void fun3(){
    cout << "fun3 start" << endl;
    myClass f3{"myClass fun3"};
    throw 1;
    cout << "fun3 end" << endl;
}
void fun2(){
    cout << "fun2 start" << endl;
    myClass f2{ "myClass fun2 "};
    fun3();
    cout << "fun2 end" << endl;

}
void fun1(){
    cout << "fun1 start" << endl;
    try{
        fun2();
    }
    catch(int){
        cout << "catch in f1" << endl;
    }
    cout << "fun1 end" << endl;

}
int main(void){
    fun1();
    return 0;
}