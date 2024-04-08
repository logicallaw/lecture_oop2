#include <iostream>
using namespace std;
class Tmp{
    friend istream& operator>>(istream& in, Tmp& right){
        in >> right.a;
        in.ignore(10, '-');
        in >> right.b;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Tmp& right){
        out << right.a << "-" << right.b << endl;
        return out;
    }
private:
    int a, b;
public:
    explicit Tmp(int a = 0, int b = 0)
    : a{ a }, b{ b }{}
};

int main(){
    Tmp t;
    cin >> t;
    cout << t;
}