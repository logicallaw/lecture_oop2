#include <iostream>
using namespace std;
int main(void){
    char str1[50];
    char str2[50];
    char str3[50];

    cin.get(str1, 50);
    cout << str1 << endl;
    cin.ignore();
    cin.get(str2,50,'\n');
    cout << str2 << endl;
    cin.ignore();
    cin.get(str3,50,'\n');
    cout << str3 << endl;
    return 0;
}