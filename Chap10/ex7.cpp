#include <iostream>
#include <array>
using namespace std;
int main(){
    array<int, 5> arr1{ 1, 2, 3};
    for(int a : arr1){
        cout << a << endl;
    }
    array arr2{1,2,3};
    for(int a : arr2){
        cout << a << endl;
    }
}