#include <iostream>
using namespace std;
int findMax(int* pa, int* pb);

int main(void){
    int a, b;
    cin >> a >> b;
    cout << findMax(&a, &b) << endl;
    return 0;
}
int findMax(int* pa, int* pb){
    return (*pa >= * pb) ? *pa : *pb;
}