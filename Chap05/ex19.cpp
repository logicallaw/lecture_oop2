#include <iostream>
using namespace std;
class Tmp{
    friend ostream& operator<<(ostream& out, const Tmp& right);
    friend int printInfo(int d);
public:
    Tmp& operator++(){ //prefix
        ++a;
        return *this;
    }
    Tmp operator++(int){ //postfix
        Tmp temp = *this;
        a++;
        return temp;
    }
    Tmp& operator+=(const Tmp& right){
        a += right.a;
        return *this;
    }
    Tmp& operator+=(int num){
        a += num;
        return *this;
    }
    Tmp()
        : a { 5 } {}
    int getA() const { return a; }
private:
    int a;
};
ostream& operator<<(ostream& out, const Tmp& right){
    out << right.a;
    return out;
}
int printInfo(int d) { return a;}
int main(void){
    Tmp t1;
    cout << ++t1 << endl; //6
    cout << t1++ << endl; //6
    cout << t1 << endl; //7

    Tmp t2; //5
    t1 += t2;
    t1 += 10;
    cout << t1 << endl; //22
}