//Overloading
/* friend 전역함수
 * friend 멤버함수
 *
 */
//friend 전역함수
#include <iostream>
using namespace std;
class Tmp{
    friend ostream& operator<<(ostream& out, const Tmp& right);
    friend istream& operator>>(istream& in, Tmp& right);
public:
    Tmp()
        : a{ 1 }, b{ 2 }, c{ 3 } {}
private:
    int a;
    int b;
    int c;
};

ostream& operator<<(ostream& out, const Tmp& right){
    out << right.a << endl;
    out << right.b << endl;
    out << right.c << endl;
    return out;
}
istream& operator>>(istream& in, Tmp& right){
    cout << "right.a: ";
    in >> right.a;
    cout << "right.b: ";
    in >> right.b;
    cout << "right.c: ";
    in >> right.c;
    return in;
}
int main(void){
    Tmp t1;
    cin >> t1;
    cout << t1;
}