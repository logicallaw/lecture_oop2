#include <iostream>
using namespace std;
int gcd(int num1, int num2);
int main(void) {
    //�Է��� �޽��ϴ�.
    int a, b;
    cout << "Please input a and b: ";
    cin >> a >> b;

    //a != b���� Ȯ���մϴ�. true�� while �����մϴ�.
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }

    //a != b�̹Ƿ� gcd�� ã���ϴ�.
    int gcdNum = gcd(a, b);

    //gcd�� ����Ѵ�.
    cout << "gcd is " << gcdNum << endl;
    return 0;

}
int gcd(int num1, int num2) {
    if (num2 == 0) return num1;
    else return gcd(num2, num1 % num2); //EX:/12,18/18,6/6,0->6���
}