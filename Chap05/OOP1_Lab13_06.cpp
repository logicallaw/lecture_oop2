#include <iostream>
using namespace std;
int getMinimumDistance(int* p, const int& size);
int main(void){
    int size;
    cout << "배열 크기를 입력해 주세요: ";
    cin >> size;
    int* nums = new int[size];

    cout << "배열 요소를 입력해 주세요: ";
    for (int i{ 0 }; i < size; i++)
        cin >> *(nums + i);

    cout << endl << "가장 작은 차이: " << getMinimumDistance(nums, size) << endl;

    delete[] nums;
    return 0;
}

int getMinimumDistance(int* p, const int& size){
    int min = *(p);
    int temp;
    for (int i{ 0 }; i < size - 1; i++){
        for (int j{ 0 }; j < size - 1 - i; j++)

    }
    return *(p + 1) - *(p);
}
/*
6
3 6 3 5 1 9
 */