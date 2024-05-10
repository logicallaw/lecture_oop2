#include <iostream>
using namespace std;

int main() {
    int number;

    // 사용자에게 숫자 입력을 요청합니다.
    cout << "숫자를 입력하세요 (입력 종료는 Ctrl+Z 또는 Ctrl+D): ";

    // 무한 루프를 사용하여 숫자를 계속 입력 받습니다.
    while (true) {
        cin >> number;

        // eof() 조건을 체크합니다.
        if (cin.eof()) {
            // Ctrl+Z 또는 Ctrl+D가 입력되면 루프를 종료합니다.
            cout << "파일 끝에 도달했습니다." << endl;
            break;
        }

        // 데이터가 제대로 입력되었는지 체크합니다.
        if (cin.good()) {
            cout << "입력된 숫자: " << number << endl;
        } else {
            // 입력 오류가 발생했을 경우, 스트림을 클리어하고 무시합니다.
            cin.clear(); // 스트림의 오류 상태를 클리어합니다.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}