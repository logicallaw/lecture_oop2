#include <iostream>
using namespace std;
int main(void){
    cout << cin.rdstate() << endl;
    cin.clear(ios::failbit);
    cout << cin.rdstate() << endl;
}