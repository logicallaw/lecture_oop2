//12210795_����ȣ
#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
    //Default: a x b = a * b
    int a, b = 1;
    for (int i{ 1 }; i <= 18; i++) {

        /*  i <= 9�̸� 2~5�ܱ��� ���� ���
            i > 9�̸� 6~9�ܱ��� ���� ��� */
        if (i <= 9)
            a = 2;
        else
            a = 6;

        // a x b = a * b ����Ѵ�.
        for (int j{ 0 }; j < 4; j++) {
            cout << a << " x " << b << " = " << setw(10) << left << a * b;
            a++;
        }
        cout << endl;

        // 2~5���� ������ b = 1�� �ʱ�ȭ�Ѵ�.
        if (i != 9) {
            b++;
        }
        else {
            b =1 ;
            cout << endl;
        }
    }
    cout << endl << endl;

    return 0;
}