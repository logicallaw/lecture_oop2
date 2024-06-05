#include <iostream>
using namespace std;

int main() {
    char c;
    while (cin.get(c)) {
        cout << "입력한 문자: " << c << endl;
    }

    if (cin.eof()) {
        cout << "파일의 끝에 도달했습니다." << endl;
    } else if (cin.fail()) {
        cout << "입력 실패!" << endl;
    }

    return 0;
}