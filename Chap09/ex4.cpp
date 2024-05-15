#include <iostream>
#include <exception>
using namespace std;

void func3() {
    cout << "f3 enter" << endl;
    throw 1;
    cout << "f3 exit" << endl;
}
void func2() {
    cout << "f2 enter" << endl;
    func3();
    cout << "f2 exit" << endl;
}
void func1(){
    cout << "f1 enter" << endl;
    try{
        func2();
    }
    catch(int value){
        cout << "catch in f1" << endl;
    }
    cout << "f1 exit" << endl;
}

int main(){
    func1();
    return 0;
}
