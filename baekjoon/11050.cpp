#include <iostream>
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    int counter = k;
    long result = 1;
    for(int i{ 0 }; i < counter; i++)
        result *= (n--);
    for(int i{ 0 }; i < counter; i++)
        result /= (k--);
    cout << result;
    return 0;
}