#include <iostream>
#include <string>

int main() {
    std::string arr[] = {"hello", "world", "!"};
    std::string *ptr = arr;

    // 배열의 길이 구하기
    int length = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Array length: " << length << std::endl;

    // 포인터를 사용하여 배열의 길이 구하기
    int ptrLength = sizeof(ptr) / sizeof(ptr[0]);
    std::cout << "Pointer length: " << ptrLength << std::endl;

    return 0;
}
