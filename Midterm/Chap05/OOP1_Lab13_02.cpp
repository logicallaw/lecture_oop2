#include <iostream>
using namespace std;
void print2Darr(int** p, const int& ROW, const int& COl);
int main(void){
    const int ROW = 3;
    const int COL = 4;
    int** arr = new int*[ROW];

    cout << "Input: " << endl;
    for (int i{ 0 }; i < ROW; i++){
        arr[i] = new int[COL];
        for (int j{ 0 }; j < COL; j++)
            cin >> arr[i][j];
    }

    cout << endl << "Output: " << endl;
    print2Darr(arr, ROW, COL);

    int* temp = arr[0];
    arr[0] = arr[2];
    arr[2] = temp;

    cout << endl << "Output2: " << endl;
    print2Darr(arr, ROW, COL);

    for (int i{ 0 }; i < ROW; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}
void print2Darr(int** p, const int& ROW, const int& COL){
    for(int i{ 0 }; i < ROW; i++){
        for (int j{ 0 }; j < COL; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
}
/*
1 2 3 4
5 6 7 8
9 0 1 2
 */