//클래스 input, output stream 오버라이딩
#include <iostream>
using namespace std;
class Tmp{
    friend istream& operator>>(istream& input, Tmp& right){
        input >> right.a;
        return input;
    }
    friend ostream& operator<<(ostream& output, const Tmp& right){
        output << right.a << endl;
        return output;
    }
private:
    int a;
public:
    Tmp(){}
    Tmp(int a)
        : a { a } {}
    Tmp& operator=(const Tmp& right){
        a = right.a;
        return *this;
    }
    bool operator==(const Tmp& right){
        return a == right.a;
    }
    Tmp& operator+=(const Tmp& right){
        a += right.a;
        return *this;
    }
    bool operator!=(const Tmp& right){
        return !(*this == right);
    }
    void print() const { cout << a << endl; }
};

int main(void){
    Tmp t1(1);
//    cin >> t1;
//    cout << "\n";
//    cout << t1;
    Tmp t2(2);
    t1 += t2;
    t1.print();
}