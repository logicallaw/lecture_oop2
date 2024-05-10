#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "정수를 입력하세요: ";
    cin >> num;

    // cin의 현재 상태를 출력합니다.
    cout << "cin의 상태: " << cin.rdstate() << endl;

    if (cin.rdstate() & ios::failbit) {
        cout << "입력 실패 (failbit)" << endl;
    }
    if (cin.rdstate() & ios::badbit) {
        cout << "스트림 문제 (badbit)" << endl;
    }
    if (cin.rdstate() & ios::eofbit) {
        cout << "파일의 끝 (eofbit)" << endl;
    }
    if (cin.rdstate() == ios::goodbit) {
        cout << "모든 것이 정상 (goodbit)" << endl;
    }

    return 0;
}