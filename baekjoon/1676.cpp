#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int cnt = n, result = 0;
    long long factorial = n;
    while(cnt--){
        if(factorial % 10 == 0){
            result++;
            factorial *= cnt;
            factorial /= 10;
        }
        else {
            factorial *= cnt;
        }
    }
    cout << result;
    return 0;
}