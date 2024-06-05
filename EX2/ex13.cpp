#include <iostream>
using namespace std;
int main(void){
    char str1[50];
    char str2[50];
    cin >> str1 >> str2;
    cout << "1: " << str1 << endl;
    cout << "2: " << str2 << endl;

    int a;
    if(cin >> a){
        cout << a << endl;
    }
    else{
        cout << "fail" << endl;
    }
}