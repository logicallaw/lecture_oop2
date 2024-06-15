#include <iostream>
using namespace std;
class Derived;
class Base{
    friend void swap(Base*, Derived*);
protected:
    int num1;
public:
    Base() : num1{ 10 } {}
    void show() { cout << "\n Value of Number 1 : " << num1; }
};

class Derived{
    friend void swap(Base*, Derived*);
protected:
    int num2;
public:
    Derived() : num2 { 20 } {}
    void show() { cout << "\n Value of Number 2 : " << num2; }
};

void swap(Base* pb, Derived* pd){
    int temp = pb->num1;
    pb->num1 = pd->num2;
    pd->num2 = temp;
}

int main(void){
    Base b;
    Derived d;
    b.show();
    d.show();

    swap(&b, &d);

    b.show();
    d.show();
    return 0;
}