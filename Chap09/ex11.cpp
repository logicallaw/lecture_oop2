#include <iostream>
#include <iomanip>

using namespace std;
int main(void){
    double root2 { 1.457 };
    cout << fixed; //고정소수점(소수점 이하 자릿수 일정하게 유지) globally
    cout << setprecision(2); //소수점 이하 자릿수 지정 가능. globally
    cout << 3.1111111 << endl;
    cout << 2.33232 << endl;
    cout << 4.23112223 << endl;
    return 0;

}