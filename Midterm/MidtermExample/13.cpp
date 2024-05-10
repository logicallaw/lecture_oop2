#include <iostream>
using namespace std;
class Tmp{
    friend ostream& operator<<(ostream& output, const Tmp& tmp){
        output << tmp.a << endl;
        output << tmp.b << endl;
        output << tmp.c << endl;
        return output;
    }
    friend istream& operator>>(istream& input, Tmp& right){
        input >> right.a;
        input.ignore();
        input >> right.b;
        input.ignore();
        input >> right.c;
        input.ignore();
        return input;
    }
private:
    int a;
    int b;
    int c;
public:
    Tmp(int a, int b, int c)
        : a{ a }, b { b }, c { c }{}

};

int main(void){
    Tmp t1(1,2,3);
    cin >> t1;
    cout << t1;
}