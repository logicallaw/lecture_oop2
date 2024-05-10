#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "문자열을 입력하세요 (개행문자 없이 100개 이상의 글자): ";

    // 사용자로부터 긴 문자열을 입력 받아 버퍼를 채웁니다.
    // 이 예에서는 개행문자를 포함하지 않는 긴 문자열을 입력한다고 가정하겠습니다.
    cin.ignore(100, '\n');

    // 사용자가 개행문자 없이 100개 이상의 글자를 입력한 경우,
    // cin.ignore(100, '\n')은 처음 100개의 글자를 무시합니다.

    string remaining;
    getline(cin, remaining); // 무시된 다음부터 개행문자까지 읽거나, 버퍼의 나머지를 모두 읽습니다.

    cout << "무시된 후 남은 문자열: " << remaining << endl; // remaining이 출력됩니다.

    return 0;
}