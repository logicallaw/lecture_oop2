#include <iostream>
using namespace std;
int main(void){
    char str1[50];
    char str2[50];
    char str3[50];

    cin.get(str1, 50);
    cout << "1: " << str1 << endl;

    cin.get(str2, 50);
    cout << "2: " << str2 << endl;

    cin.get(str3, 50);
    cout << "3: " << str3 << endl;

    return 0;
}