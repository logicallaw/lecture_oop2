#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    double num1{ 0.00056789765 };
    double num2{ 12.062392 };
    double num3{ 0.00126};
    double num4{ 0.001054 };
    cout << setprecision(2) << num4 << endl;
    cout << setprecision(2) << num3 <<endl;
    cout << setprecision(3) << num2 << endl;
}