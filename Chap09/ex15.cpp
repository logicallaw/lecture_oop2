#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    char sentence[10];
    cout << "Enter a sentence." << endl;
    cout.width(5);
    while(cin >> sentence){
        cout << cout.width() << endl;
    }



}