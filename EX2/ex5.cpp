#include <iostream>
using namespace std;
template<typename T>
void swap(T* a1, T* a2){
//    T temp = *a1;
//    *a1 = *a2;
//    *a2 = temp;
    T temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
template<typename T>
void bubbleSort(T arr[], int n){
    for (int i = 0; i < n - 1;  i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void){
    int arr1[] = {5, 2, 9, 1, 5, 6};
    bubbleSort(arr1, 6); // 정렬 후: 1, 2, 5, 5, 6, 9


    double arr2[] = {4.5, 2.1, 9.3, 1.8, 5.7};
    bubbleSort(arr2, 5); // 정렬 후: 1.8, 2.1, 4.5, 5.7, 9.3
}