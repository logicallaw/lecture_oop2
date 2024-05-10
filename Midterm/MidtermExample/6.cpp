#include <iostream>
using namespace std;
int main(void){
    //deep copy
    int* p1 = new int{11};
    int* p2 = new int{*p1};
    delete p1;
    cout << *p2 << endl;
}