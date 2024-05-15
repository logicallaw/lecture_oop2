#include <iostream>
using namespace std;
bool isRightTriangle(const int& a, const int& b, const int& c);
int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    while(a != 0){
        if(isRightTriangle(a,b,c))
            cout << "right" << "\n";
        else
            cout << "wrong" << "\n";
        cin >> a >> b >> c;
    }
    return 0;
}

bool isRightTriangle(const int& a, const int& b, const int& c){
    if(a >= b){
        if(a >= c) return (a * a == b * b + c * c);
         else return (c * c == a * a + b * b);
    }
    else{
        if(b >= c) return (b * b == a * a + c * c);
        else return (c * c == a * a + b * b);
    }
}

