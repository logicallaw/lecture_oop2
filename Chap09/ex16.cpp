#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    cout.width(5);
    cout << "lee" << setw(7) << "wook" << endl;
    cout.width( 5);
    cout << "dlwlrma" << setw(7) << "wook" << endl << endl;

    char str1[10];
    cin >> setw(5) >> str1;
    cout << str1 << endl;

    cin >> setw(5) >> str1;
    cout << str1 << endl;
    return 0;
}