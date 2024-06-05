#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Padding 예제
    cout << right << setw(10) << setfill('*') << 123 << endl;
    cout << right << setw(10) << setfill('*') << 1234 << endl;
    cout << right << setw(10) << setfill('*') << 12345 << endl;

    // Padding 예제 2
    cout << left << setw(10) << setfill('#') << 123 << endl;
    cout << left << setw(10) << setfill('#') << 1234 << endl;
    cout << left << setw(10) << setfill('#') << 12345 << endl;

    // showbase와 internal 사용 예제
    cout << showbase << internal;
    cout << setw(10) << 123 << endl;
    cout << setw(10) << -123 << endl;
    cout << setw(10) << hex << 123 << endl;

    return 0;
}