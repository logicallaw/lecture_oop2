#include <iostream>
using namespace std;
int main(void){
    int widthValue{ 4 };
    char sentence[10];
    cout << "Enter a sentence:\n";
    while(cin >> sentence){
        cout.widen(widthValue++);
        cout << sentence << endl;
        cin.width(5);
    }
}