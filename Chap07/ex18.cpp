#include <iostream>
using namespace std;
int main(void){
    char str1[10];
    cin.getline(str1,3);
    cout << str1 << endl;
    cin.clear();
    char str2[10];
    cin.getline(str2, 10);
    cout << str2 << endl;
    return 0;
}