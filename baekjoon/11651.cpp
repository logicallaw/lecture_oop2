/* n by 2행렬
 * 모든 좌표는 항상 정수
 * 위치가 동일한 두 좌표는 없다.
 * 정렬할 건데 y좌표 작은거->큰거. 같은게 있다면 x좌표도 증가하는 순으로.
 */
#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int** matrix = new int*[n];
    for(int i{ 0 }; i < n; i++)
        matrix[i] = new int[2];
    for(int i{ 0 }; i < n; i++)
        for(int j{ 0 }; j < 2; j++)
            cin >> matrix[i][j];
    int** dest = new int*[n];


    for(int i{ 0 }; i < n; i++)
        delete matrix[i];
    delete[] matrix;
    return 0;
}