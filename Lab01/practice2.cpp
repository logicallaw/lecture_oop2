/*
�Էµ� ������ -1 �� �ϸ鼭 �� ����ϱ�
*/
#include <iostream>
using namespace std;
int main(void) {
    int num;
    cout << "Please input one number:";
    cin >> num;
    for (int i{ num }; i >= 1; i--) {
        for (int j{ i }; j >= 1; j--) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}