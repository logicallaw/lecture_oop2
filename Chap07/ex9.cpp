#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 존재하지 않는 파일을 열 시도
    ifstream file("nonexistentfile.tx");

    // 파일 스트림에 오류가 있는지 체크
    if (file.bad()) {
        cout << "파일을 여는 데 실패했습니다. 스트림이 손상되었습니다." << endl;
    } else {
        cout << "파일을 성공적으로 열었습니다." << endl;
    }

    // 다른 작업...

    file.close();
    return 0;
}