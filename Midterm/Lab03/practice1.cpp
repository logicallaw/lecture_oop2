#include <iostream>
using namespace std;
class Practice1 {
private:
    int a, b, c;
    int* pnum = new int[3];
public:
    Practice1()
            : a{ 1 }, b{ 2 }, c{ 3 } {
        cout << "I am a default constructor." << endl;
    }
    Practice1(int a, int b, int c)
            : a{ a }, b{ b }, c{ c } {
        cout << "I am a parameter constructor." << endl;
    }
    Practice1(const Practice1& origin)
            : a { origin.a}, b { origin.b }, c{ origin.c} {
        cout << "I am a copy constructor." << endl;
    }
    ~Practice1() {
        delete[] pnum;
        cout << "I am a destructor." << endl;
    }
    void print() const {
        cout << "a is " << a << ", b is " << b << ", c is " << c << "." << endl;
    }
};
int main(void) {
    Practice1 d;
    Practice1 p(1, 2, 3);
    Practice1 c = p;
    c.print();
}