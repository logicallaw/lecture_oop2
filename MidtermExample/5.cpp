//shallow copy VS deep copy
#include <iostream>
using namespace std;
int main(void){
    //shallow copy
    int* p1 = new int{5};
    int* p2 = p1;
    delete p1;
    cout << *p2 << endl;
}