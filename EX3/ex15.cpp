#include <iostream>
using namespace std;
class Base{
public:
    virtual int f(int num){
        cout << "f(int) in base: ";
        return num + 4;
    }
    virtual double f(double num){
        cout << "f(double) in base: ";
        return num * 2 - 0.1;
    }
};

class Derived: public Base{
public:
    virtual int f(int num){
        cout << "f(int) in derived: ";
        return num + 4;
    }
    virtual double f(double num){
        cout << "f(double) in derived: ";
        return num * 2;
    }
};

int main(void){
    Derived* dp = new Derived;
    cout << dp->f(3) << endl;
    cout << dp->f(3.3) << endl;

    Base* bp = dp;
    cout << bp->f(4) << endl;
    cout << bp->f(4.4) << endl;
    delete dp;
    return 0;
}