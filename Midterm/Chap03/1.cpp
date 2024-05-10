#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
    int a, b = 1;
    for (int i{ 1 }; i <= 18; i++) {
        if (i <= 9)
            a = 2;
        else
            a = 6;

        for (int j{ 0 }; j < 4; j++) {
            cout << a << " x " << b << " = " << setw(10) << left << a * b;
            a++;
        }
        cout << endl;

        if (i != 9) {
            b++;
        }
        else {
            b = 1 ;
            cout << endl;
        }

    }
    cout << endl;
    return 0;
}