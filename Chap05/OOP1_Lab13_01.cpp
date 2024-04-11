#include <iostream>
using namespace std;
int main(void){
    int size;
    cout << "배열의 크기를 입력해 주세요: ";
    cin >> size;
    int* nums = new int[size];

    for (int i{ 0 }; i < size; i++)
        *(nums + i) = i;

    for (int i{ 0 }; i < size; i++)
        cout << *(nums + i) << " ";

    delete[] nums;
    return 0;
}